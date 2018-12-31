let bool_check = Alcotest.(check(bool));
let assert_true = (msg, value) => bool_check(msg, true, value);

let last_opt_tests = [
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

let read_lines_from_file_tests = [
  (
    "test read_lines_from_file with a basic file",
    `Quick,
    () =>
      assert_true(
        "returns a list of strings",
        ReasonHelpers.Util.read_lines_from_file("test/input/input1.txt")
        == ["One", "Two", "Three"],
      ),
  ),
  (
    "test read_lines_from_file with empty file",
    `Quick,
    () =>
      assert_true(
        "returns an empty list",
        ReasonHelpers.Util.read_lines_from_file("test/input/empty.txt") == [],
      ),
  ),
  (
    "test read_lines_from_file with non-existant file",
    `Quick,
    () =>
      Alcotest.check_raises(
        "raises exception",
        Sys_error("test/input/does-not-exist.txt: No such file or directory"),
        () =>
        ReasonHelpers.Util.read_lines_from_file(
          "test/input/does-not-exist.txt",
        )
        |> ignore
      ),
  ),
];

let swap_tests = [
  (
    "test swap with a simple list",
    `Quick,
    () =>
      assert_true(
        "returns the swapped list",
        ReasonHelpers.Util.swap(0, 1, ["one", "two"]) == ["two", "one"],
      ),
  ),
  (
    "test swap with a bigger list",
    `Quick,
    () =>
      assert_true(
        "returns the swapped list",
        ReasonHelpers.Util.swap(3, 1, ['a', 'b', 'c', 'd', 'e'])
        == ['a', 'd', 'c', 'b', 'e'],
      ),
  ),
  (
    "test swap with a bigger list",
    `Quick,
    () =>
      Alcotest.check_raises("raises exception", Failure("nth"), () =>
        ReasonHelpers.Util.swap(0, 1, ['a']) |> ignore
      ),
  ),
];

let remove_first_char_tests = [
  (
    "remove the first char from a string",
    `Quick,
    () =>
      assert_true(
        "returns the new string",
        ReasonHelpers.Util.remove_first_char("abc") == "bc",
      ),
  ),
  (
    "removes nothing from an empty string",
    `Quick,
    () =>
      assert_true(
        "returns an empty string",
        ReasonHelpers.Util.remove_first_char("") == "",
      ),
  ),
];

let remove_last_char_tests = [
  (
    "remove the last char from a string",
    `Quick,
    () =>
      assert_true(
        "returns the new string",
        ReasonHelpers.Util.remove_last_char("abc") == "ab",
      ),
  ),
  (
    "removes nothing from an empty string",
    `Quick,
    () =>
      assert_true(
        "returns an empty string",
        ReasonHelpers.Util.remove_last_char("") == "",
      ),
  ),
];

let string_to_chars_tests = [
  (
    "get list of chars for a string",
    `Quick,
    () =>
      assert_true(
        "returns the list of chars",
        ReasonHelpers.Util.string_to_chars("abc") == ['a', 'b', 'c'],
      ),
  ),
  (
    "get list of chars for an empty string",
    `Quick,
    () =>
      assert_true(
        "returns an empty list",
        ReasonHelpers.Util.string_to_chars("") == [],
      ),
  ),
];

let lev_distance_tests = [
  (
    "compute lev distance of two same strings",
    `Quick,
    () =>
      assert_true(
        "returns 0",
        ReasonHelpers.Util.lev_distance("Hello", "Hello") == 0,
      ),
  ),
  (
    "compute lev distance of two different strings",
    `Quick,
    () =>
      assert_true(
        "returns 3",
        ReasonHelpers.Util.lev_distance("Kitten", "Sitting") == 3,
      ),
  ),
  (
    "compute lev distance of a string that is empty",
    `Quick,
    () =>
      assert_true(
        "returns 5",
        ReasonHelpers.Util.lev_distance("", "Hello") == 5,
      ),
  ),
];

let test_suites: list(Alcotest.test(unit)) = [
  ("Test last_opt", last_opt_tests),
  ("Test read_lines_from_file", read_lines_from_file_tests),
  ("Test swap", swap_tests),
  ("Test remove_first_char", remove_first_char_tests),
  ("Test remove_last_char", remove_last_char_tests),
  ("Test string_to_chars", string_to_chars_tests),
  ("test lev_distance", lev_distance_tests),
];

let () = Alcotest.run("proj", test_suites);