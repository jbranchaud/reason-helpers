/* get the last item out of a list */
let rec last_opt = (items: list('a)): option('a) =>
  switch (items) {
  | [] => None
  | [last_item] => Some(last_item)
  | [_, ...rest] => last_opt(rest)
  };