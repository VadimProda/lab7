﻿begin
  var (chas, min, sek) := ReadReal3('Введите кол-во часов, минут, секунд');
  var a := min;
  min := a*60;
  var b := chas;
  chas := b * 60**2;
  print(chas + min + sek)
end.

(*
Введите кол-во часов, минут, секунд 2 5 30
7530 

Введите кол-во часов, минут, секунд 0 10 50
650 

Введите кол-во часов, минут, секунд 0 11 6
666 

Введите кол-во часов, минут, секунд 24 0 0
86400 






*)