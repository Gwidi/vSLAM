camOut =[];
for k = 1:numel(camPoses)
    camOut = [camOut;camPoses(k).A];

end
camOut