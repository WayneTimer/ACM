program P2239;
var
  n:integer;
  a:array[1..127,1..300] of boolean;
  used:array[1..127] of boolean;
  ma:array[1..300] of integer;
procedure init;
  var
    i,j,w,x,y:integer;
  begin
    fillchar(a,sizeof(a),false);
    readln(n);
    for i:=1 to n do
      begin
        read(w);
        for j:=1 to w do
          begin
            read(x,y);
            a[y*10+x,i]:=true;
          end;
        readln;
      end;
  end;

function find(x:integer):boolean;
  var
    i:integer;
  begin
    if not used[x] then
      for i:=1 to n do
        if a[x,i] then
          begin
            used[x]:=true;
            if (ma[i]=0) or find(ma[i]) then
              begin
                ma[i]:=x;
                exit(true);
              end;
          end;
    find:=false;
  end;

procedure main;
  var
    i,s:integer;
  begin
    s:=0;
    for i:=1 to 127 do
      begin
        fillchar(used,sizeof(used),false);
        if find(i) then inc(s);
      end;
    writeln(s);
  end;

begin
  while not eof do
    begin
      init;
      main;
    end;
end.