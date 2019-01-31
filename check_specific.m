function [] = check_specific(Told)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
        prompt = 'What event do you want to check?: ';
        str = input(prompt,'s');
        Told.Properties.RowNames = Told.Event;
        t1 = datetime('now');
        t2 = datetime(table2array(Told(str,'Year')),table2array(Told(str,'Month')),table2array(Told(str,'Day')),table2array(Told(str,'Hour')),table2array(Told(str,'Minutes')),0);
        dt = between(t1,t2); 
        disp(dt);
end

