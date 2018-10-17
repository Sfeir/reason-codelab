let rec pow = (a, exp) =>
  switch (exp) {
  | 0 => 1.
  | 1 => a
  | n when n > 1 => a *. pow(a, exp - 1)
  | _ => raise(Failure("argument out of range"))
  };

let fact = x => {
  let rec aux = (acc, y) =>
    switch (y) {
    | 0 => acc
    | n => aux(n * acc, n - 1)
    };
  aux(1, x);
};

let volume = radius => 4. *. Js.Math._PI *. pow(radius, 3) /. 3.;