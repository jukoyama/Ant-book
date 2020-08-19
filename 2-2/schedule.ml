let n = 5
let s = [1; 2; 4; 6; 8]
let t = [3; 5; 7; 9; 10]

let plst = List.sort compare (List.map2 (fun a b -> (b, a)) s t)

let time = ref 0

let solve = List.fold_left
    (fun n (p1, p2) -> if (!time < p2) then (time := p1; n + 1) else n) 0 plst
