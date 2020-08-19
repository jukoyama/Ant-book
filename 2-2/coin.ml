let v = [1; 5; 10; 50; 100; 500]      

let c = [3; 2; 1; 3; 0; 2]       

let a = ref 620

let rec solve = 
  List.fold_right2
    (fun v' c' n' -> let x = min (!a/v') c' in (a := !a - x * v'; n' + x))
    v c 0
