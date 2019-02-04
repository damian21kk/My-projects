function [] = save_function(T)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
while true
    
    prompt = "What is the name of the file?\n";
    str = input(prompt, 's');
    if (exists(prompt+'.xlsx','file')~=0)
        
        fprintf("This file already exists\n");
        continue;
        
    else
        
        break;
        
    end

end

writetable(T, str+'.xlsx');

end

