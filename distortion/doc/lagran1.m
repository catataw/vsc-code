%lagran1.m  
%求拉格朗日插值多项式和基函数  
%输入的量:n+1个节点(x_i,y_i)(i = 1,2, ... , n+1)横坐标向量X，纵坐标向量Y  
%输出的量：n次拉格朗日插值多项式L及其系数向量C，基函数l及其系数矩阵L  
function [C,L,L1,l] = lagran1(X,Y)  
m = length(X); 
L = ones(m,m);  
for k = 1 : m  
    V = 1;  
    for i = 1 : m  
        if k ~= i  
            V = conv(V,poly(X(i))) / (X(k) - X(i));  
        end  
    end  
    L1(k, :) = V; l(k, :) = poly2sym(V);  
end  
C = Y * L1;  
L = Y * l; 