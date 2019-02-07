function [newcell] = New_event(Told)
%New_event creates a new event that has not be defined yet but other events already exist
%   This function in contradiction to new_table does not return a table but it returns a cell that can insertet to already existinng table of events. It also checks if the new event has not been defined aready and if the date of the event is real and in the future.

datetime.setDefaultFormats('default','yyyy-MM-dd hh:mm:ss');

while true

    while true

        prompt = 'What is the event?: ';
        Event = input(prompt,'s');

        if isempty(Event)

            fprintf('Please give the name of the event!\n');
            continue;

        else

            break;

        end

    end

    A=strcmp(Event,Told.Event);

    if all(A==0)

        break;

    else

        fprintf("This event already exists\n");

    end

end

while true

%checking if the date given by the user is valid, ex. the day is not negative or >31

        while true

            prompt = '\nWhat year?: ';
            Year = input(prompt);

            if isempty(Year)

						fprintf("Please give the year!\n");
						continue;

            elseif Year < 0

                fprintf('Year cannot be negative');
                continue;

            else 

                break;

            end

        end

        while true

            prompt = '\nWhat month?: ';
            Month = input(prompt);

            if isempty(Month)

						fprintf("Please give the month!\n");
						continue;

            elseif Month < 1

                fprintf('Month cannot be less than 1');
                continue;

            elseif Month > 12

                fprintf('Month cannot be greater than 12\n');
                continue;

            else

                break;

            end

        end

        while true

            prompt = '\nWhat day?: ';
            Day = input(prompt);

            if isempty(Day)

						fprintf("Please give the day!\n");
						continue;

            elseif Day < 1

                fprintf('Day cannot be less than 1');
                continue;

            elseif Month==1 && Day > 31 || Month==3 && Day > 31 || Month==5 && Day > 31 || Month==8 && Day > 31 || Month==10 && Day > 31 || Month==12 && Day > 31

                fprintf('Day cannot be greater than 31\n');
                continue;

            elseif Month==4 && Day > 30 || Month==6 && Day > 30 || Month==7 && Day > 30 || Month==9 && Day > 30 || Month==11 && Day > 30

                fprintf('Day cannot be greater than 30\n');
                continue;

            elseif Month==2 && rem(Year,4)==0 && Day > 29

                fprintf('Day cannot be greater than 29\n');
                continue;

            elseif Month==2 && rem(Year,4)~=0 && Day > 28

                fprintf('Day cannot be greater than 29\n');
                continue;

            else 

                break;

            end

        end

        while true

            prompt = '\nAt what time (hour)?: ';
            Hour = input(prompt);

            if isempty(Hour)

						fprintf("Please give the hour!\n");
						continue;

            elseif Hour < 0

                fprintf('Hour cannot be negative');
                continue;

            elseif Hour > 23

                fprintf('Hour cannot be greater than 23\n');
                continue;

            else 

                break;

            end

        end

        while true

            prompt = '\nAt what time (minutes)?: ';
            Minutes = input(prompt);

            if isempty(Minutes)

						fprintf("Please give the minutes!\n");
						continue;

            elseif Minutes < 0

                fprintf('Minutes cannot be negative');
                continue;

            elseif Minutes > 59

                fprintf('Minutes cannot be greater than 59\n');
                continue;

            else

                break;

            end

        end

%checking if the event is not in a past

        t1 = datetime('now');
        t2 = datetime(Year,Month,Day,Hour,Minutes,0);
        dt = t2-t1;
        sec=seconds(dt);

        if sec > 0

            break;

        end

end

    newcell = {Event,t2};

end

