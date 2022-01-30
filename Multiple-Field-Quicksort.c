#include <stdio.h>

typedef struct meeting_ {
	int s;
	int e;
} meeting;

void swap(meeting *a, meeting *b) {
	meeting tmp_swap;
	tmp_swap = *a;
	*a = *b;
	*b = tmp_swap;
}

void quickSort(meeting *arr, int L, int R) { // 정렬 할 배열, Left , Right
	meeting pivot = arr[(L+R) / 2];
	if (L >= R) return; // 종료 조건
	
	int left = L, right = R;
	while (left <= right) { // 두 커서가 겹치지 않을 동안 

		while ((arr[left].e < pivot.e) || ((arr[left].e == pivot.e) && (arr[left].s < pivot.s))) // 다중 조건 퀵정렬
			left++;

		while ((pivot.e < arr[right].e) || ((pivot.e == arr[right].e) && (pivot.s < arr[right].s))) // 다중 조건 퀵정렬
			right--;

		if (left <= right) {
			if (left != right) // 정렬은 같지 않을 때만 필요하고, left++, right-- 는 같아도 필요하다. (재귀 호출시 pivot_index를 제외하고 호출하기 위해서)
				swap(&arr[left], &arr[right]);

			// 바꾸고 나면 arr[left]는 arr[pivot_index] 보다 작을 것이고
			// arr[right]는 arr[pivot_index]보다 클 것이 보장되어 있기 때문에
			// 다시 검사하는 일을 줄이기 위해 left++, right--
			left++;
			right--;
		}
	}

	quickSort(arr, L, right);
	quickSort(arr, left, R);
}

int main()
{
	int N; 

	scanf("%d", &N); // 회의 수

	meeting mt_arr[N];
	for (int i = 0 ; i < N; i++) {
		scanf("%d %d", &mt_arr[i].s, &mt_arr[i].e);
	}

	quickSort(mt_arr, 0, N-1); // 정렬 할 배열, Left , Right

	int cnt = 1;
	int now_time = mt_arr[0].e;
	for (int i = 1 ; i < N; i++) {
		if (now_time <= mt_arr[i].s) {
			now_time = mt_arr[i].e;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}

// 5
// 6 7
// 6 6
// 5 6
// 5 5
// 7 7
