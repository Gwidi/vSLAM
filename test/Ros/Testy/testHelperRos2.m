function testHelperRos2(message)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

global imgArr
imgMsg = message;
imgData = imgMsg.data;
width = imgMsg.width;
height = imgMsg.height;
step = imgMsg.step;

% Przykład dla obrazu RGB
imageArray = reshape(imgData, [step, height]); % Przyjmując, że imgData jest wektorem obrazu w skali szarości
imageArray = imageArray(1:width, :); % Wybierz tylko dane obrazu
imgArr = reshape(imageArray, [width, height])'; % Zmień rozmiar na poprawny
disp('odebrano');

end

