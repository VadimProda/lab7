begin
var a := ReadInteger;
case a of
  4..10:Print('Доброе утро, мир!');
  11..16:Print('Добрый вечер, мир!');
  17..22:Print('Доброй ночи, мир!');
  else Print('Доброй ночи, мир!');
end;
end.