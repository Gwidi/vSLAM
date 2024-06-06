function send_ROS(A, pub, camPoses, pub2)
    % Tworzenie wiadomości ROS
    msg = ros2message(pub);

    % Liczba punktów
    num_points = size(A, 1);

    % Przekształcenie macierzy Nx3 na wektor 1x(3*N) w formacie [x1, y1, z1, x2, y2, z2, ...]
    reshaped_A = reshape(A', 1, []);  % Transpozycja A, a następnie przekształcenie na wektor

    % Konfiguracja layoutu wiadomości
    msg.layout.dim(1).label = 'points';
    msg.layout.dim(1).size = uint32(num_points);
    msg.layout.dim(1).stride = uint32(numel(reshaped_A));
    msg.layout.data_offset = uint32(0);

    % Przypisanie przekształconego wektora do wiadomości ROS
    msg.data = reshaped_A;  
    disp('Dodano macierz:');
    disp(A);

    % Publikowanie wiadomości ROS
    send(pub, msg);
    disp('Message sent.');

    % Liczba macierzy
    num_poses = numel(camPoses);

    % Inicjalizacja dużego wektora o długości N*16 (gdzie N to liczba macierzy)
    large_vector = zeros(1, num_poses * 16);

    % Wypełnianie dużego wektora przekształconymi macierzami z camPoses
    for i = 1:num_poses
        large_vector((i-1)*16 + 1:i*16) = reshape(camPoses(i).A', 1, []);
    end

    % Tworzenie wiadomości ROS
    msg2 = ros2message(pub2);

    % Konfiguracja layoutu wiadomości
    msg2.layout.dim(1).label = 'elements';
    msg2.layout.dim(1).size = uint32(numel(large_vector));
    msg2.layout.dim(1).stride = uint32(numel(large_vector));
    msg2.layout.data_offset = uint32(0);

    % Przypisanie dużego wektora do wiadomości ROS
    msg2.data = double(large_vector);  % Konwersja do typu double
    disp('Dodano macierze:');
    disp(large_vector);

    % Publikowanie wiadomości ROS
    send(pub2, msg2);
    disp('Message sent.');

    
end