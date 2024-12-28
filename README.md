## SEKURO17_TubesProg
Tubes Programming untuk SEKURO 17 

Tubes ini menggunakan file URDF untuk mendeskripsikan model robot dan node ROS 2 untuk mengontrol robot melalui komunikasi antar topik.

## Cara Kerja
# File URDF (Unified Robot Description Format)
File URDF digunakan untuk mendeskripsikan struktur robot, dengan komponen sebagai berikut:
- Link: Bagian statis robot seperti bodi dan roda.
- Joint: Hubungan antara link untuk memungkinkan pergerakan, seperti roda yang terhubung ke bodi.
- Plugin Gazebo: Digunakan untuk menghubungkan simulasi robot dengan ROS melalui topik seperti /cmd_vel.

# Simulasi Gazebo
Simulasi robot secara visual dan pergerakan menggunakan Gazebo. Robot akan diimpor ke Gazebo menggunakan spawn_entity.py dan adanya plugin Gazebo memastikan bahwa robot dapat menerima perintah dari ROS

# Move Robot Node
Node ini berfungsi untuk mengontrol robot dengan mem-publish kecepatan linier dan anguler robot ke topik /cmd_vel.

## Alur Kerja Sistem ROS
Alur kerja dimulai dengan meluncurkan simulasi Gazebo menggunakan ros2 launch, di mana robot diimpor ke simulasi melalui skrip spawn_entity.py berdasarkan deskripsi pada file URDF. Node ROS 2 bernama move_robot kemudian dijalankan untuk mengirimkan perintah kecepatan berupa pesan ke topik /cmd_vel yang diterima oleh plugin Gazebo untuk menggerakkan robot di simulasi. Plugin ini juga menerbitkan data odometri ke topik /odom dan status joint ke topik /joint_states untuk memberikan umpan balik terkait posisi, orientasi, dan kondisi robot.
