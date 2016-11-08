%lagran1.m  
%���������ղ�ֵ����ʽ�ͻ�����  
%�������:n+1���ڵ�(x_i,y_i)(i = 1,2, ... , n+1)����������X������������Y  
%���������n���������ղ�ֵ����ʽL����ϵ������C��������l����ϵ������L  
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