cam = webcam();
I = snapshot(cam);
I = snapshot(cam);
mkdir('img')
for i = 1:10
I = snapshot(cam);
tic
% Podczas procesu przetwarzania obrazu
% otrzymanego z kamery uzyskalem ponizsze czasy:
%Elapsed time is 0.288970 seconds.
% Elapsed time is 0.274503 seconds.
% Elapsed time is 0.272751 seconds.
% Elapsed time is 0.281168 seconds.
% Elapsed time is 0.273345 seconds.
% Elapsed time is 0.273346 seconds.
% Elapsed time is 0.288479 seconds.
% Elapsed time is 0.278336 seconds.
% Elapsed time is 0.280042 seconds.
% Elapsed time is 0.271564 seconds.
imwrite(I,cat(2,'./img/',num2str(i),'.png'));
toc
end
