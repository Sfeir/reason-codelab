module Request = {
  type t;

  [@bs.get] external path: t => string = "";
  [@bs.get] external json: t => Js.Json.t = "body";
  [@bs.get] external params: t => Js.Dict.t(string) = "";
};

module Response = {
  type t;

  [@bs.send] external sendText: (t, string) => unit = "send";
  [@bs.send] external sendJson: (t, Js.Json.t) => unit = "json";
  [@bs.send] external sendStatus: (t, int) => unit = "";
  [@bs.send] external status: (t, int) => t = "";
};

type handler = (Request.t, Response.t) => unit;
type middleware;

module App = {
  type t;

  [@bs.send] external use: (t, middleware) => t = "";
  [@bs.send] external get: (t, string, handler) => t = "";
  [@bs.send] external post: (t, string, handler) => t = "";
  [@bs.send] external listen: (t, int, unit => unit) => unit = "";
};

[@bs.module] external makeApp: unit => App.t = "express";
[@bs.module "express"] external json: unit => middleware = "";