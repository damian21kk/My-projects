function [] = save_function(T)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
while true
    
    prompt = 'What is the name of the file?\n';
    str = input(prompt,'s');
    filename= str + ".xlsx";
    
    if (exist(filename,'file')~=0)
        
        fprintf("This file already exists\n");
        continue;
        
    else
        
        break;
        
    end

end

writetable(T, filename);

end

