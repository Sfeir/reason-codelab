open Belt;

let sum = (a, b) => a + b;
let prod = (a, b) => a * b;

{
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
};