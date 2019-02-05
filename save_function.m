function [] = save_function(T)
%save_funtion saves the data to a file named by the user
%   The data is saved in a spreadsheet

while true
    
    prompt = 'What is the name of the file?\n';
    str = input(prompt,'s');
    filename= str + ".xlsx";
    if isempty(str)
        
        fprintf("Please give the name of the file!\n");
        continue;
        
    elseif (exist(filename,'file')~=0)
        
        fprintf("This file already exists\n");
        continue;
        
    else
        
        break;
        
    end

end

writetable(T, filename);

end

