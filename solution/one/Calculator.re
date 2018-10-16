let answer = 42;

let pi = 3.14159;

let message = "the answer is";

let response = message ++ string_of_int(answer);

let justAChar = 'C';

let aroundTheAnswer = 2. *. pi *. float_of_int(answer);

let add = (a, b) => a +. b;

let circumference = radius => 2. *. pi *. radius;

let surface = radius => pi *. radius ** 2.;

let rec pow = (a, exp) =>
  if (exp === 0) {
    1.;
  } else if (exp === 1) {
    a;
  } else {
    a *. pow(a, exp - 1);
  };

let rec pow' = (a, exp) =>
  switch (exp) {
  | 0 => 1.
  | 1 => a
  | n when n > 1 => a *. pow(a, exp - 1)
  | _ => raise(Failure("argument out of range"))
  };

let volume = radius => 4. *. pi *. pow(radius, 3) /. 3.;

let couple = (1, 2);
let (a, b) = couple;
let aList = [1, 2, 3];
let [a, b, ...t] = aList;
let anArray = [|1, 2, 3|];
let [|a, b, c|] = anArray;

let isEqual = [[1, 2], [3, 4]] == [[1, 2], [3, 4]];

open Belt;

let calc = () => {
  let oper = Node.Process.argv->Array.getExn(2);
  let args =
    Node.Process.argv->Array.sliceToEnd(3)->Array.map(float_of_string);

  switch (oper, args) {
  | ("+", [|a, b|]) => string_of_float(add(a, b))
  | ("vol", [|r|]) => string_of_float(volume(r))
  | _ => "???"
  };
};

Js.log2(message, calc());