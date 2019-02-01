function [] = check_specific(Told)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');
        while true
            prompt = 'What event do you want to check?: ';
            str = input(prompt,'s');
            if isempty(str)
                fprintf("Please give the name of the event!\n");
                continue;
            end
            A=strcmp(str,Told.Event);
            if all(A==0)
                fprintf('This event is not saved\n');
                continue;  
            else
                break;
            end
        end
        Told.Properties.RowNames = Told.Event;
        t1 = datetime('now');
        t2 = datetime(table2array(Told(str,'Date')));
        dt = between(t1,t2); 
        disp(dt);
end

