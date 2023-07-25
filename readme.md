# Flappy Bird Remake !<img src="assets/game/icon.png" alt= "icon" width=40>
remake do jogo flappy bird utilizado a [SFML lib](https://www.sfml-dev.org/index.php) com c++

## Branch baseada em Windows 
- <strong>Como Rodar?</strong><br>

1- baixe o mingw e a lib sfml nas versões corretas:

- [SFML](https://www.sfml-dev.org/index.php)

- [MinGW](https://www.mingw-w64.org)


2- abra sua IDE com a pasta fonte e configure o makefile:
<img src="assets/game/makefile.png" alt="makefile"> 
Atualize o path do seu SFML, colocando o \include no compile e o \lib no link<br> <br>

3- Edite o c_cpp_properties.json
<img src= "assets/game/json.png" alt="jsoncproperties">
siga os comentarios e adicione os paths referentes

<strong> obs: caso necessário, linke o path da sfml e do compilador g++