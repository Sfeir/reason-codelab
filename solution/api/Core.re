open Belt;
open Express;
open Express.Response;

let tryParseParam = (key, cast, req) => {
  let params = Request.params(req);
  try (params->Js.Dict.unsafeGet(key)->cast->Result.Ok) {
  | Failure(err) => Result.Error(err)
  };
};

let tryDecodeJson = (decode, req) =>
  try (decode(Request.json(req))->Result.Ok) {
  | Json.Decode.DecodeError(err) => Result.Error(err)
  };

let sayHelloWorld = (_, res, _) => sendText(res, "Hello World!");

let volume = (req, res, _) => {
  let response =
    Result.(
      tryParseParam("rad", float_of_string, req)
      ->map(Operation.volume)
      ->map(string_of_float)
    );

  switch (response) {
  | Ok(r) => sendText(res, r)
  | Error(_) => sendStatus(res, 400)
  };
};

let factorial = (req, res, _) => {
  let decode = tryDecodeJson(Json.Decode.(field("n", int)));
  let encode = n => Json.Encode.(object_([("answer", int(n))]));

  let response = Result.(decode(req)->map(Operation.fact)->map(encode));

  switch (response) {
  | Ok(r) => sendJson(res, r)
  | Error(_) => sendStatus(res, 400)
  };
};