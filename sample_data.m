baseDownloadURL = "https://cvg.cit.tum.de/rgbd/dataset/freiburg3/rgbd_dataset_freiburg3_long_office_household.tgz"; 
dataFolder      = fullfile(tempdir, 'tum_rgbd_dataset', filesep); 
options         = weboptions(Timeout=Inf);
tgzFileName     = [dataFolder, 'fr3_office.tgz'];
folderExists    = exist(dataFolder, "dir");

% Create a folder in a temporary directory to save the downloaded file
if ~folderExists  
    mkdir(dataFolder); 
    disp('Downloading fr3_office.tgz (1.38 GB). This download can take a few minutes.') 
    websave(tgzFileName, baseDownloadURL, options); 
    
    % Extract contents of the downloaded file
    disp('Extracting fr3_office.tgz (1.38 GB) ...') 
    untar(tgzFileName, dataFolder); 
end