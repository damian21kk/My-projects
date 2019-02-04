function [] = check_all(Told)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here


datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');

clc;
fprintf("Time to the following events:\n");

n = size(Told);

        parfor (i = 1:n(1)) 
        
                t1 = datetime('now');
                t2 = datetime(table2array(Told(i,2)));
                dt = between(t1,t2); 
                fprintf("%s		%s\n", char(table2array(Told(i,1))), dt);      
        end
end