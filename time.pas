﻿begin
  var a := ReadInteger('Введите номер года');
  if a mod 4 = 0 then
    print('кол-во дней 366')
  else if (a mod 100 = 0) and (a mod 400 <> 0) then
    print('кол-во дней 365')
  else
    print('кол-во дней 365')
end.


(*
Введите номер года 2015
кол-во дней 365 

Введите номер года 2012
кол-во дней 366 

Введите номер года 2023
кол-во дней 365 

*)