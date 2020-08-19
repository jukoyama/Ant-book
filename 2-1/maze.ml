let n = 10
let m = 10
let (sx, sy) = (1, 0)
let (gx, gy) = (8, 9)

let l =
  [['#';'S';'#';'#';'#';'#';'#';'#';'.';'#'];
   ['.';'.';'.';'.';'.';'.';'#';'.';'.';'#'];
   ['.';'#';'.';'#';'#';'.';'#';'#';'.';'#'];
   ['.';'#';'.';'.';'.';'.';'.';'.';'.';'.'];
   ['#';'#';'.';'#';'#';'.';'#';'#';'#';'#'];
   ['.';'.';'.';'.';'#';'.';'.';'.';'.';'#'];
   ['.';'#';'#';'#';'#';'#';'#';'#';'.';'#'];
   ['.';'.';'.';'.';'#';'.';'.';'.';'.';'.'];
   ['.';'#';'#';'#';'#';'.';'#';'#';'#';'.'];
   ['.';'.';'.';'.';'#';'.';'.';'.';'G';'#']]

type direction = Up | Down | Right | Left

(* 移動後の座標 *)
let move (x, y) dir = match dir with
  | Up    -> (x, y-1)
  | Down  -> (x, y+1)
  | Right -> (x+1, y)
  | Left  -> (x-1, y)

(* キュー *)
let open_list = [(sx, sy)]
                
(* 最短距離を格納する配列 *)
let close_list = Array.make_matrix n m (0, true)

(* スタート地点をリセット *)
let () = Array.set (Array.get close_list sy) sx (0, false)

(* 受け取った座標を一度通ったことがあるか判定 *)
let not_passed (x, y) = snd (Array.get (Array.get close_list y) x)

(* 受け取った座標が壁でないか判定 *)
let not_wall (x, y) =
  if (0 <= x && x < n && 0 <= y && y < m) then
    if ( List.nth (List.nth l y) x != '#' && not_passed (x, y)) then true
    else false
  else false

(* 座標と動く方向を受け取ったら、配列を更新し、移動後の座標を返す *)
let koushin (x, y) dir lst =
  (* 移動した座標 *)
  let (nx, ny) = move (x, y) dir in
  (* 移動前までにかかった歩数 *)
  let (count, b) = Array.get (Array.get close_list y) x in
  if not_wall (nx, ny) then
    (Array.set (Array.get close_list ny) nx (count+1, b);
     (nx, ny) :: lst)
  else lst

(* 幅優先探索 *)
let rec bfs (x, y) lst =
  match lst with
  | [] -> Array.get (Array.get close_list y) x
  | first :: rest ->
    if ( first = (gx, gy) ) then bfs first []
    else
      let nl = koushin first Up (koushin first Left
               (koushin first Right (koushin first Down rest))) in
      bfs first nl
      
let ans = bfs (sx, sy) open_list
