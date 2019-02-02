function [] = delete_function()
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    if (exist('Timer.txt','file')==0)
        clc
        fprintf("No data saved\n");
        return;
    end
    while true
            prompt = 'Are you sure you want to delete? Yes[Y]/No[N]:\n ';
            str = input(prompt,'s');
            if (isempty(str))||(str~='Y') && (str~='N')
                fprintf("Wrong command, please try again!\n");
                continue;
            elseif str=='Y'
                clc;
                clear;
                delete Timer.xlsx;
                delete Timer.txt;
                break;
            elseif str=='N'
                clc;
                break;
            end
    end
end

