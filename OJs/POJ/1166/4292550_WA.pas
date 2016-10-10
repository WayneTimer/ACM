program clocks;
const
  c:array[1..9,1..9]of integer=
    ((3,3,3,3,3,2,3,2,0),
    (2,3,2,3,2,3,1,0,1),
    (3,3,3,2,3,3,0,2,3),
    (2,3,1,3,2,0,2,3,1),
    (2,3,2,3,1,3,2,3,2),
    (1,3,2,0,2,3,1,3,2),
    (3,2,0,3,3,2,3,3,3),
    (1,0,1,3,2,3,2,3,2),
    (0,2,3,2,3,3,3,3,3));
var
  t:array[1..9] of integer;
procedure init;
  var
    i:integer;
  begin
    readln(t[1],t[2],t[3]);
    readln(t[4],t[5],t[6]);
    readln(t[7],t[8],t[9]);
    for i:=1 to 9 do
      t[i]:=t[i] div 3;
  end;

procedure main;
  var
    i,j,k:integer;
    s:ansistring;
    a:array[1..9] of integer;
  begin
    fillchar(a,sizeof(a),0);
    for i:=1 to 9 do
      for k:=1 to 9 do
        inc(a[k],c[i,k]*(4-t[i]));
    for i:=1 to 9 do
      a[i]:=a[i] and 3;
    s:='';
    for i:=1 to 9 do
      for j:=1 to a[i] do
        s:=s+chr(i+48)+' ';
    delete(s,length(s),1);
    write(s);
    writeln;
  end;

begin
  init;
  main;
end.