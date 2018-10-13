open Belt;

let sum = (a, b) => a + b;
let prod = (a, b) => a * b;

/* {
     let operation = Node.Process.argv->Array.getExn(2);
     let operands =
       Node.Process.argv->Array.sliceToEnd(3)->Array.map(int_of_string);
     let result =
       switch (operation) {
       | "+" => operands->Array.reduce(0, sum)
       | "x" => operands->Array.reduce(1, prod)
       | _ => 404
       };
     Js.log(result);
   }; */

/* {
     let operation = Node.Process.argv->Array.get(2);
     let result =
       switch (operation) {
       | Some(op) =>
         let operands =
           Node.Process.argv->Array.sliceToEnd(3)->Array.map(int_of_string);
         switch (op) {
         | "+" => operands->Array.reduce(0, sum)->string_of_int
         | "x" => operands->Array.reduce(1, prod)->string_of_int
         | _ => "I can't do " ++ op
         };
       | None => "You have to tell me what to do"
       };

     Js.log(result);
   }; */

let intOfStringOrNone = x =>
  try (int_of_string(x)->Some) {
  | Failure(_) => None
  };

let calc = (xs, op, init) =>
  xs->List.keepMap(intOfStringOrNone)->List.reduce(init, op);

{
  let command = Node.Process.argv->Array.sliceToEnd(2)->List.fromArray;
  let result =
    switch (command) {
    | ["+", ...operands] => operands->calc(sum, 0)->Result.Ok
    | ["x", ...operands] => operands->calc(prod, 1)->Result.Ok
    | [op, ..._] => Result.Error("I can't do " ++ op)
    | _ => Result.Error("You have to tell me what to do")
    };

  Js.log(
    switch (result) {
    | Result.Ok(n) => "-> " ++ string_of_int(n)
    | Result.Error(e) => e
    },
  );
};