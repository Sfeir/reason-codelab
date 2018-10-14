open Belt;

type entry =
  | Add
  | Mult
  | Num(float)
  | Unknown;

let parse = token =>
  try (float_of_string(token)->Num) {
  | Failure(_) =>
    switch (token) {
    | "+" => Add
    | "*" => Mult
    | _ => Unknown
    }
  };

let make = () => {
  let stack = ref([]);

  input => {
    let newStack =
      switch (parse(input), stack^) {
      | (Num(n), stack) => [n, ...stack]
      | (Add, [a, b, ...t]) => [a +. b, ...t]
      | (Mult, [a, b, ...t]) => [a *. b, ...t]
      | (_, stack) => stack
      };

    stack := newStack;
    List.(newStack->reverse->map(string_of_float)->toArray);
  };
};