clear all; close all;clc;
% Find a Bluetooth connection object.
obj1 = instrfind('Type', 'bluetooth', 'Name', 'Bluetooth-HCO5:1', 'Tag', '');

% Create the Bluetooth connection object if it does not exist
% otherwise use the object that was found.
if isempty(obj1)
    obj1 = Bluetooth('HCO5', 1);
else
    fclose(obj1);
    obj1 = obj1(1);
end

% Connect to instrument object, obj1.
fopen(obj1);

c1=1;
m=1;
c=1;
Power=0;
Power1=zeros(11,1);
t1=zeros(11, 1);
t01=0;
while m<1000
    tic 
    tstart=tic;
        c=c+1;
            dfred1=fscanf(obj1);
    dt = toc(tstart);
    Power5 = powertemp1(dfred1);
    if ~isempty(Power5)
        Power1(c1,1)=Power5;
    t1(c1,1)=t01+dt;
    t01=t1(c1);
     drawnow;
     figure(1)
     plot(t1,Power1,'r')
     title ('Generated Power by PV Device')
     legend('PV Device')
     xlabel('Time (s)')
     ylabel('Real Power (mW)')
     grid on

    c1=c1+1;
    end
% m=m+1;

end


