function [T] = new_table()
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    prompt = 'What is the event?: ';
    Event = input(prompt,'s');
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
    T=table(Event,Year,Month,Day,Hour,Minutes);
end

