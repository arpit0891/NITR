function [ lat ] = worstLatency( sp, n )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
max = 0;
for i = 1 : n
    for j = 1 : noc
        if (sp (j,i) > max) %if the shortest path is greater than the maximum value
            max = sp (j,i);%update the maximum value
        end
    end
end
lat = max;
end