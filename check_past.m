function [T] = check_past(T)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
 
 
clc;
datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');
 
n = size(T);
 
        for (i = 1:n(1)) 
        
                t1 = datetime('now');
                t2 = datetime(table2array(T(i,2)));
                dt = t2 - t1;
						sec = seconds(dt);
						
						if sec < 0
							
							T(i,:) = [];
						
						end;
        
        end
end