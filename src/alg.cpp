// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        res += 1;
      }
    }
  }
  return res;
}

int countPairs2(int* arr, int len, int value) {
  int res = 0;
  int start = 0;
  int end = len - 1;
  int start_amount = 1;
  int end_amount = 1;
  int equal = 0;

  if ((arr[start] > value) || (arr[end] / 2 < value)) {
    return 0;
  }

  while ((arr[end] >= value) || (arr[start] + arr[end] > value)) {
    end--;
  }
  if (start >= end) {
    return 0;
  }

  while ((start < end) && (arr[start] != arr[end])) {
    int start_amount = 1;
    int end_amount = 1;
    while (arr[end] == arr[end - 1]) {
      end--;
      end_amount++;
    }
    while (arr[start] == arr[start + 1]) {
      start++;
      start_amount++;
    }
    res += start_amount * end_amount;
  }
  equal = end - start;
  res += equal * (equal + 1) / 2;
  return res;
}

int countPairs3(int* arr, int len, int value) {
  int start = 0;
  int end = len - 1;
  int max = value - arr[start];

  if ((arr[start] > value) || (arr[end] / 2 < max)) {
    return 0;
  }

  int cur = 0;

  while (end - start > 1) {
    cur = start + (end - start) / 2;
    if (arr[cur] <= max) {
      start = cur;
    } else {
      end = cur;
    }
  }

  if (arr[end] == max) {
    cur = end;
  } else if (arr[start] == max) {
    cur = start;
  }

  int res = 0;
  int equal = 0;
  end = cur;
  start = 0;
  while ((start < end) && (arr[start] != arr[end])) {
    int start_amount = 1;
    int end_amount = 1;
    while (arr[end] == arr[end - 1]) {
      end--;
      end_amount++;
    }
    while (arr[start] == arr[start + 1]) {
      start++;
      start_amount++;
    }
    res += start_amount * end_amount;
  }
  equal = end - start;
  res += equal * (equal + 1) / 2;
  return res;
}
