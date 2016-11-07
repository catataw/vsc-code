#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <assert.h>

#include "psmove.h"
#include "psmove_tracker.h"
#include "package.h"

float qx, qy, qz, qw;
float roll, yaw, pitch;
int move_count = 0;
PSMove **controllers;
int main(int arg, char** args) {
	int i;
	void *frame;
	int result;
	printf("等待手柄连接......\n");
	while (1)
	{
		move_count = psmove_count_connected();//有多少个手柄连接
		printf("### Found %d controllers.\n", move_count);
		if (move_count != 0)break;
		Sleep(200);
	}//如果有手柄连接，继续向下执行
	printf("手柄连接成功\n");

	controllers = (PSMove **)calloc(move_count, sizeof(PSMove *));

	fprintf(stderr, "Trying to init PSMoveTracker...");
	PSMoveTrackerSettings settings;
	psmove_tracker_settings_set_default(&settings);
	settings.color_mapping_max_age = 0;
	settings.exposure_mode = Exposure_LOW;
	settings.camera_mirror = PSMove_True;

	PSMoveTracker* tracker = psmove_tracker_new_with_settings(&settings);
	if (!tracker)
	{
		fprintf(stderr, "Could not init PSMoveTracker.\n");
		return 1;
	}
	fprintf(stderr, "OK\n");


	for (i = 0; i<move_count; i++) {
		printf("Opening controller %d\n", i);
		controllers[i] = psmove_connect_by_id(i);//根据获得具体的psmove对象的指针
		//assert(controllers[i] != NULL);
		if (controllers[i] == NULL)
		{
			printf("controllers %i error\n", i);
			scanf("%d", &i);
		}
		psmove_enable_orientation(controllers[i], PSMove_True);//设置相应psmove的欧拉角

		for (;;) {
			printf("Calibrating controller %d...", i);
			fflush(stdout);
			result = psmove_tracker_enable(tracker, controllers[i]);//将move绑定到tracker 设置move内部的颜色

			if (result == Tracker_CALIBRATED) {
				enum PSMove_Bool auto_update_leds =
					psmove_tracker_get_auto_update_leds(tracker,
					controllers[i]);
				printf("OK, auto_update_leds is %s\n",
					(auto_update_leds == PSMove_True) ? "enabled" : "disabled");
				break;
			}
			else {
				printf("ERROR - retrying\n");
			}
		}
	}//for 绑定每个psmove
	do_init = 1;

	while (1) {
		psmove_tracker_update_image(tracker);//Retrieve the next image from the camera
		psmove_tracker_update(tracker, NULL);//Process incoming data and update tracking information追踪算法
		psmove_tracker_annotate(tracker);//Draw debugging information onto the current camera image打印调试信息

		frame = psmove_tracker_get_frame(tracker);
		if (frame) {
			printf("yes\n");
		}

		for (i = 0; i<move_count; i++) {
			float x, y, r;
			psmove_tracker_get_position(tracker, controllers[i], &x, &y, &r);
			printf("x: %10.2f, y: %10.2f, r: %10.2f", x, y, r);

			psmove_get_orientation(controllers[i], &qw, &qx, &qy, &qz);
			printf("[%.2f%.2f%.2f%.2f]\n", qx, qy, qz, qw);

		}
	}

	for (i = 0; i<move_count; i++) {
		psmove_disconnect(controllers[i]);
	}

	psmove_tracker_free(tracker);
	free(controllers);

	return 0;
}
