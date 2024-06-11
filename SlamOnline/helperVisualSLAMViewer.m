classdef helperVisualSLAMViewer < pcplayer
% helperVisualSLAMViewer plots map points and camera trajectory 
% obtained from visual SLAM.
% Copyright 2023 The MathWorks, Inc.

    properties (GetAccess = ?matlab.unittest.TestCase)
        % Camera trajectory plot
        CameraTrajectory
        
        % Camera plot
        CurrentCamera
    end    

    methods(Access=public)
        function obj = helperVisualSLAMViewer(xyzPoints,cameraPoses)

            trajectory = vertcat(cameraPoses.Translation);
            
            % Create a pcplayer object
            parent = newplot(figure(Visible="off"));
            obj@pcplayer([-3.00 3.00], [-2.00 2.00], [-1.00 4.00], ...
                MarkerSize=6, ...                
                VerticalAxis="y", ...
                VerticalAxisDir="down", ...
                Parent=parent);
            
            % Create new viewer plot
            if ~isempty(cameraPoses)
                createViewer(obj,xyzPoints,cameraPoses(end),trajectory);
            end
        end

        function createViewer(obj,xyzPoints,currCameraPose,trajectory)
            
            obj.view(xyzPoints,"b");
            hold(obj.Axes,"on")            
            % Create new trajectory plot
            obj.CameraTrajectory = plot3(obj.Axes, trajectory(:,1), trajectory(:,2), ...
                trajectory(:,3), Color='r', LineWidth=2, ...
                DisplayName="Camera trajectory");
            % Create new camera plot
            obj.CurrentCamera = plotCamera(AbsolutePose=currCameraPose, ...
                Parent=obj.Axes, Size=0.1, Color="y");
            
            hold(obj.Axes,"off")
        end

        function updatePlot(obj,xyzPoints,cameraPoses)

            if strcmpi(obj.Figure.Visible, 'off')
                figure(obj.Figure); % bring to front
            end

            if isempty(cameraPoses)
                return
            end
            
            trajectory = vertcat(cameraPoses.Translation);
            
            % Update map points
            if ~isempty(xyzPoints)
                obj.view(xyzPoints,"b");
            end
            % Update camera trajectory
            set(obj.CameraTrajectory, XData=trajectory(:,1), ...
                YData=trajectory(:,2), ...
                ZData=trajectory(:,3))
            % Update camera poses
            currPose = cameraPoses(end);
            obj.CurrentCamera.AbsolutePose=currPose;

            drawnow('limitrate')
        end
    end
end