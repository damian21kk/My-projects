function [] = check_specific(Told)
%check_specific checks the remaining plan to only one specific event 
%   This function checks time to an event defined by the user saved previously in the Timer.txt file

datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');

%asking the user for the event

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
        
%calculating time remaining to the event

        Told.Properties.RowNames = Told.Event;
        t1 = datetime('now');
        t2 = datetime(table2array(Told(str,'Date')));
        dt = between(t1,t2); 
        disp(dt);

end

