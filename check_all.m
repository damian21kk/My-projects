function [] = check_all(Told)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here


datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');

fprintf("Time to the following events:\n");

n = size(Told);

        forpar 1:n 
        
                t1 = datetime('now');
                t2 = datetime(table2array(Told(n,2)));
                dt = between(t1,t2); 
                disp(table2array(Told(n,1)),':' dt);
                
        end;
        
end