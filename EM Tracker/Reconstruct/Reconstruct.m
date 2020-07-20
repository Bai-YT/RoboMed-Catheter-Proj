clear
close all
figure
hold off

data = xlsread('1.xlsx');
Tx1 = data(:, 9);
Ty1 = data(:, 10);
Tz1 = data(:, 11);
Tx2 = data(:, 101);
Ty2 = data(:, 102);
Tz2 = data(:, 103);
Tx3 = data(:, 193);
Ty3 = data(:, 194);
Tz3 = data(:, 195);
while 1
    k = round(input('Please enter the index of the data: '));
    if k <= 0
        return; % To quit the program, input a non-positive number
    end
    plot3([Tx1(k), Tx2(k), Tx3(k)], [Ty1(k), Ty2(k), Tx3(k)], [Tz1(k), Tz2(k), Tx3(k)]);
    xlabel x
    ylabel y
    zlabel z
end