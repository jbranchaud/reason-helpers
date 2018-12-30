let bool_check = Alcotest.(check(bool));
let assert_true = (msg, value) => bool_check(msg, true, value);

let tests = [
  (
    "test last_opt with empty list",
    `Quick,
    () =>
      assert_true("returns None", ReasonHelpers.Util.last_opt([]) == None),
  ),
  (
    "test last_opt with non-empty list",
    `Quick,
    () =>
      assert_true(
        "returns Some",
        ReasonHelpers.Util.last_opt([1, 2, 3]) == Some(3),
      ),
  ),
  (
    "test last_opt with a single item list",
    `Quick,
    () =>
      assert_true(
        "returns Some",
        ReasonHelpers.Util.last_opt(["one"]) == Some("one"),
      ),
  ),
];

let test_suites: list(Alcotest.test(unit)) = [("Assert True", tests)];

let () = Alcotest.run("proj", test_suites);