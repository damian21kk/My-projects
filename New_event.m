function [newcell] = New_event(Told)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
prompt = 'What is the event?: ';
while true
    Event = input(prompt,'s');
    A=strcmp(Event,Told.Event);
    if all(A==0)
        break;        
    end
end
while true
        prompt = '\nWhat year?: ';
        Year = input(prompt);
        prompt = '\nWhat month?: ';
        Month = input(prompt);
        prompt = '\nWhat day?: ';
        Day = input(prompt);
        prompt = '\nAt what time (hour)?: ';
        Hour = input(prompt);
        prompt = '\nAt what time (minutes)?: ';
        Minutes = input(prompt);
        t1 = datetime('now');
        t2 = datetime(Year,Month,Day,Hour,Minutes,0);
        dt = t2-t1;
        sec=seconds(dt);
        if sec>0
            break;
        end
end
    newcell={Event,Year,Month,Day,Hour,Minutes};
end

