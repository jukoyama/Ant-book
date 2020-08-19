let n = 10
let m = 12
let l = [|[|'W';'.';'.';'.';'.';'.';'.';'.';'.';'W';'W';'.'|];
          [|'.';'W';'W';'W';'.';'.';'.';'.';'.';'W';'W';'W'|];
          [|'.';'.';'.';'.';'W';'W';'.';'.';'.';'W';'W';'.'|];
          [|'.';'.';'.';'.';'.';'.';'.';'.';'.';'W';'W';'.'|];
          [|'.';'.';'.';'.';'.';'.';'.';'.';'.';'W';'.';'.'|];
          [|'.';'.';'W';'.';'.';'.';'.';'.';'.';'W';'.';'.'|];
	  [|'.';'W';'.';'W';'.';'.';'.';'.';'.';'W';'W';'.'|];
	  [|'W';'.';'W';'.';'W';'.';'.';'.';'.';'.';'W';'.'|];
	  [|'.';'W';'.';'W';'.';'.';'.';'.';'.';'.';'W';'.'|];
	  [|'.';'.';'W';'.';'.';'.';'.';'.';'.';'.';'W';'.'|]|]

let rec dfs x y dx dy =
  if dy > 1 then 1
  else if dx > 1 then dfs x y (-1) (dy+1)
  else                         
    (Array.set (Array.get l y) x '.';
    let nx = x + dx in
    let ny = y + dy in
    if (0 > nx) || (nx >= m) || (0 > ny) || (ny >= n) then dfs x y (dx+1) dy
    else if (Array.get (Array.get l ny) nx) = 'W' then
      dfs nx ny (-1) (-1)
    else dfs x y (dx+1) dy)
   

let rec solve i j ans =
  if i >= n then ans
  else if j >= m then solve (i+1) 0 ans
  else
  if (Array.get (Array.get l i) j) = 'W' then
    let r = ans + (dfs j i (-1) (-1)) in
    solve i (j+1) r
  else solve i (j+1) ans

let ans = solve 0 0 0
