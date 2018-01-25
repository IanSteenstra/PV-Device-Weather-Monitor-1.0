function mydata = powertemp1(data)
token=strtok(data,'Power:');
token2=strtok(token,'mW');
mydata=str2num(token2);
end