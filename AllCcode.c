#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.14159265
//#include<time.h>
//#define   WIN32_LEAN_AND_MEAN
//#include <windows.h>
//#define swap(a,b) {int t; t=a; a=b; b=t; }
/////////////////////////////////////

//1851////
#include <stdio.h>

#define MAXN 100
#define MAXW 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, T;
    int w[MAXN], v[MAXN];
    int dp[MAXW] = {0};

    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = T; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    printf("%d\n", dp[T]);

    return 0;
}




/*



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;

}
int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
//qsort(a, n, sizeof(int), comp);

//132E//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char input_string[100];
	char* decimal_point_location;
	int round_up_indicator, i;

	while (scanf("%s", input_string) != EOF) {
		decimal_point_location = strstr(input_string, ".");

		if (decimal_point_location == NULL) {
			printf("%s.00\n", input_string);
		}
		else {
			round_up_indicator = 0;

			if (*(decimal_point_location + 3) > '4') {
				round_up_indicator = 1;

				for (i = decimal_point_location - input_string + 2; i >= 0; i--) {
					if (input_string[i] == '.') continue;
					input_string[i] += round_up_indicator;

					if (input_string[i] <= '9') {
						round_up_indicator = 0;
						break;
					}
					else {
						input_string[i] = '0';
					}
				}
			}
			*(decimal_point_location + 3) = '\0';

			if (round_up_indicator == 0) {
				printf("%s\n", input_string);
			}
			else {
				printf("1%s\n", input_string);
			}
		}
		printf("\n");
	}
	return 0;
}


/*





//152C//2607
#include <stdio.h>

#define MAX 10
#define DIGITS 3

void radixsort(int A[], int n) {
	int i, m = 0, exp = 1;
	int bucket[1000], temp[MAX];
	for (i = 0; i < n; i++) {
		if (A[i] > m)
			m = A[i];
	}

	while (m / exp > 0) {
		for (i = 0; i < MAX; i++)
			temp[i] = 0;

		for (i = 0; i < n; i++)
			temp[(A[i] / exp) % 10]++;

		for (i = 1; i < MAX; i++)
			temp[i] += temp[i - 1];

		for (i = n - 1; i >= 0; i--)
			bucket[--temp[(A[i] / exp) % 10]] = A[i];

		for (i = 0; i < n; i++)
			A[i] = bucket[i];
		exp *= 10;

		for (i = 0; i < n-1; i++)
			printf("%d ", A[i]);
		printf("%d\n", A[i]);
	}
}

int main() {
	int n;
	while (scanf("%d", &n), n != -1) {
		int A[1000];
		int i = 0;
		A[i++] = n;
		while (scanf("%d", &n), n != -1) {
			A[i++] = n;
		}
		radixsort(A, i);
	}
	return 0;
}


///151E//1754
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, d,i,k[1000],j;
	while (scanf("%d", &k[0]) != EOF) {
		b = 1;
		while (1) {
			scanf("%d", &k[b]);
			if (k[b] == -1)break;
			b++;
		}
		int high = b - 1, low = 0;
		j = k[b - 1];
		int t = 50;
		while (t--) {
			for (a = low; a < b ; a++) {
				if (k[a] >= j) {
					low = a;
					k[high] = k[a];
					break;
				}
			}
			for (a = high-1; a >= 0; a--) {
				if (k[a] <= j) {
					high = a;
					k[low] = k[a];
					break;
				}
			}
			if (high <= low) {
				k[low] = j;
				break;
			}

		}
		for (a = 0; a < b-1; a++) {
			printf("%d ", k[a]);
		}
		printf("%d\n", k[a]);
	}
	return 0;
}
#define N 1000
int g[N][N];
int v[N];
int n, m;

void DFS(int node) {
	v[node] = 1;
	for (int i = 1; i <= n; i++) {
		if (g[node][i] == 1 && !v[i]) {
			DFS(i);
		}
	}
}

int main() {

	while (scanf("%d", &n), n) {
		scanf("%d", &m);
		memset(g, 0, sizeof(g));
		memset(v, 0, sizeof(v));
		int u, k;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &k);
			g[u][k] = g[k][u] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				DFS(i);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->right = node->left = NULL;
	return node;
}

struct TreeNode* buildTree(int* data, int len, int index) {
	if (index < len && data[index] != 0) {
		struct TreeNode* root = createNode(data[index]);
		root->left = buildTree(data, len, index * 2 + 1);
		root->right = buildTree(data, len, index * 2 + 2);
		return root;
	}
	return NULL;
}

void preOrder(struct TreeNode* root, int dep) {
	int d = dep;
	if (root != NULL) {
		if (d == 1) { printf("%d", root->val); }
		else { printf(" %d", root->val); }
		preOrder(root->left, d + 1);
		preOrder(root->right, d + 1);
	}


}
int main() {
	int n;

	scanf("%d", &n);
	while (n--) {
		int data[1000] = { 0 };
		int num, i = 0;
		while (scanf("%d", &num) && num != -1) {
			data[i] = num;
			i++;
		}
		struct TreeNode* root = buildTree(data, i, 0);

		preOrder(root, 1);
		printf("\n");
	}
	return 0;
}



///1863
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int len;
void ff(int n, int m, int flag[]) {
	if (n < 1 || m < 1) { return; }
	if (n > m) { n = m; }
	if (n == m) {
		if (n != len) { printf("\n"); }
		flag[n - 1] = 1;
		for (int i = len - 1, j = 0; i >= 0; i--) {
			if (flag[i] == 1) {
				printf(j == 0 ? "%d" : " %d", i + 1);
				j = 1;
			}
		}
		printf("\n");
		flag[n - 1] = 0;
	}
	flag[n - 1] = 1;
	ff(n - 1, m - n, flag);
	flag[n - 1] = 0;
	ff(n - 1, m, flag);
}
int main()
{
	int m, flag[1000];
	scanf("%d", &m);
	len = m;
	memset(flag, 0, sizeof(flag));
	ff(m, m, flag);
	return 0;
}
///1861
int main() {
	int n, m, a[1000] = {1};


	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		a[i] = 1;
	}
	int res = n; int j = 0,i=1;
	while (res > 1) {
		if (a[i]) {j++;}
		if (j == m) { a[i] = 0; res--; j = 0; }
		i++;
		if (i > n) { i = 1; }
	}
	for (i = 1; i <= n; i++) {
		if (a[i]) {printf("%d\n",i); }
	}
	return 0;
}

//82F//2355

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
	int row;
	int col;
	int value;
} Triple;

int find_position(Triple matrix[], int n, int row, int col) {
	for (int i = 0; i < n; i++) {
		if (matrix[i].row == row && matrix[i].col == col) {
			return i;
		}
	}
	return -1;
}

int main() {
	Triple matrixA[MAX_SIZE], matrixB[MAX_SIZE], result[MAX_SIZE];
	int row, col, value;
	int indexA = 0, indexB = 0, indexResult = 0;

	while (true) {
		scanf("%d,%d,%d", &row, &col, &value);
		if (row == -1 && col == -1 && value == -1) {
			break;
		}
		matrixA[indexA].row = row;
		matrixA[indexA].col = col;
		matrixA[indexA].value = value;
		indexA++;
	}

	while (true) {
		scanf("%d,%d,%d", &row, &col, &value);
		if (row == -1 && col == -1 && value == -1) {
			break;
		}
		matrixB[indexB].row = row;
		matrixB[indexB].col = col;
		matrixB[indexB].value = value;
		indexB++;
	}

	for (int i = 0; i < indexA; i++) {
		for (int j = 0; j < indexB; j++) {
			if (matrixA[i].col == matrixB[j].row) {
				int newRow = matrixA[i].row;
				int newCol = matrixB[j].col;
				int newValue = matrixA[i].value * matrixB[j].value;

				int position = find_position(result, indexResult, newRow, newCol);
				if (position != -1) {
					result[position].value += newValue;
				}
				else {
					result[indexResult].row = newRow;
					result[indexResult].col = newCol;
					result[indexResult].value = newValue;
					indexResult++;
				}
			}
		}
	}

	if (indexResult == 0) {
		printf("No non-zero number exists!\n");
	}
	else {
		for (int i = 0; i < indexResult; i++) {
			printf("%d,%d,%d\n", result[i].row, result[i].col, result[i].value);
		}
	}

	return 0;
}
//1856///
int main() {
	int a[1000],n=0;
	int ans, tmp;

	while (scanf("%d", &a[n])!=EOF) {
		n++;
	}
	tmp = a[0]; ans = a[0];
	for (int i = 1; i < n; i++) {
		tmp = (tmp > 0) ? tmp + a[i] : a[i];
		if (ans < tmp) { ans = tmp; }
	}
	printf("%d", ans);
	return 0;
}
////lisp//2033
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR_LEN 1000

int compute(char* expr, int* pos) {
	while (expr[*pos] == ' ') {
		(*pos)++;
	}

	if (expr[*pos] == '(') {
		(*pos)++;
		char op = expr[*pos];
		(*pos) += 2;

		int res = (op == '+' || op == '*') ? (op == '+' ? 0 : 1) : compute(expr, pos);

		while (expr[*pos] != ')') {
			if (op == '+') {
				res += compute(expr, pos);
			}
			else if (op == '-') {
				res -= compute(expr, pos);
			}
			else if (op == '*') {
				res *= compute(expr, pos);
			}
			else if (op == '/') {
				res /= compute(expr, pos);
			}
		}
		(*pos)++;

		return res;
	}
	else {
		int num = 0;
		while (expr[*pos] >= '0' && expr[*pos] <= '9') {
			num = num * 10 + (expr[*pos] - '0');
			(*pos)++;
		}

		return num;
	}
}

int main() {
	char expr[MAX_EXPR_LEN];
	fgets(expr, MAX_EXPR_LEN, stdin);
	int pos = 0;

	printf("%d\n", compute(expr, &pos));
	return 0;
}


//1851////
#include <stdio.h>

#define MAXN 100
#define MAXW 1000

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, T;
	int w[MAXN], v[MAXN];
	int dp[MAXW] = {0};

	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &w[i], &v[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = T; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}

	printf("%d\n", dp[T]);

	return 0;
}


int main() {
	int n;
	int a[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}


	return  0;
}


void checkWeek(char ch) {
	switch (ch) {
	case 'M': printf("Monday\n"); break;
	case 'W': printf("Wednesday\n"); break;
	case 'F': printf("Friday\n"); break;
	default: printf("Wrong data\n");
	}
}

int main() {
	char ch, next_ch;
	while ((ch = getchar()) != 'Y') {
		if (ch == 'S' || ch == 'T') {
			next_ch = getchar();
			if (ch == 'S') {
				if (next_ch == 'u') {
					printf("Sunday\n");
				}
				else if (next_ch == 'a') {
					printf("Saturday\n");
				}
				else {
					printf("Wrong data\n");
					ungetc(next_ch, stdin);  // push the character back to the input
				}
			}
			else if (ch == 'T') {
				if (next_ch == 'u') {
					printf("Tuesday\n");
				}
				else if (next_ch == 'h') {
					printf("Thursday\n");
				}
				else {
					printf("Wrong data\n");
					ungetc(next_ch, stdin);  // push the character back to the input
				}
			}
		}
		else {
			checkWeek(ch);
		}
	}
	return 0;
}

int main() {
	char a[1000];
	int w[1000] = { 0 };
	int deep = 0, d = 1, maxw = 0;
	gets(a);
	int i = 0;
	while ( i < strlen(a)) {
		if (a[i] == '(') {
			d++;
			if (d > deep) { deep = d; }
		}
		if (a[i] == ')') {
			d--;
		}
		if (a[i] >= 'A'&& a[i] <= 'Z') {
			w[d]++;
			if (w[d] > maxw) { maxw = w[d]; }
		}
		i++;
	}
	printf("%d %d\n", deep, maxw);
	return 0;
}
///121E//
#include <stdio.h>

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	int arr[3000];
	for (int i = 0; i <= n; i++) arr[i] = 0; // Initialize all elements to zero

	arr[r] = 1;

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a]++;
		arr[b]++;
	}

	if (n % 2 == 0) {
		int i = 1;
		for (;  i<= n; i++) {
			if (arr[i] != 3) {
				break;
			}
		}
		if (arr[i] != 2) {
			printf("no\n");
			return 0;
		}
		i++;
		for (; i <= n; i++) {
			if (arr[i] != 1) {
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n");
		return 0;
	}
	else {
		int i = 1;
		for (; i <= n; i++) {
			if (arr[i] != 3) {
				break;
			}
		}
		for (; i <= n; i++) {
			if (arr[i] != 1) {
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n");
		return 0;
	}
}

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->right = node->left = NULL;
	return node;
}

struct TreeNode* buildTree(int* data, int len, int index) {
	if (index < len && data[index] != 0) {
		struct TreeNode* root = createNode(data[index]);
		root->left = buildTree(data, len, index * 2 + 1);
		root->right = buildTree(data, len, index * 2 + 2);
		return root;
	}
	return NULL;
}

int depth(struct TreeNode* root) {
	if (root == NULL) { return 0; }
	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);
	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
void preOrder(struct TreeNode* root, int dep) {
	int d = dep;
	if (root != NULL) {
		if (d == 1) { printf("%d", root->val); }
		else { printf(" %d", root->val); }
		preOrder(root->left, d + 1);
		preOrder(root->right, d + 1);
	}
}
int flag = 1;
void midOrder(struct TreeNode* root, int dep) {
	int d = dep;
	if (root != NULL) {

		midOrder(root->left, d + 1);
		if (flag == 1) { printf("%d", root->val); flag = 0; }
		else { printf(" %d", root->val); }
		midOrder(root->right, d + 1);

	}
}
void postOrder(struct TreeNode* root, int dep) {
	int d = dep;
	if (root != NULL) {

		postOrder(root->left, d + 1);
		postOrder(root->right, d + 1);
		if (d == 1) { printf("%d", root->val); }
		else { printf("%d ", root->val); }
	}
}
int main() {
	int n;

	scanf("%d", &n);
	while (n--) {
		int data[1000] = { 0 };
		int num, i = 0;
		while (scanf("%d", &num) && num != -1) {
			data[i] = num;
			i++;
		}
		struct TreeNode* root = buildTree(data, i, 0);
		printf("%d ", depth(root));
		//preOrder(root, 1);
		//printf("\n");
		flag = 1;
		midOrder(root, 1);
		printf("\n");
	}
	return 0;
}




struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->right = node->left = NULL;
	return node;
}

struct TreeNode* buildTree(int* data, int len, int index) {
	if (index < len && data[index] != 0) {
		struct TreeNode* root = createNode(data[index]);
		root->left= buildTree(data, len, index*2+1);
		root->right = buildTree(data, len, index * 2 + 2);
		return root;
	}
	return NULL;
}
int depth(struct TreeNode* root) {
	if (root == NULL) { return 0; }
	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);
	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
void preOrder(struct TreeNode* root,int dep) {
	int d = dep;
	if(root!=NULL) {
		if (d == 1) { printf("%d", root->val); }
		else { printf(" %d", root->val); }
		preOrder(root->left, d + 1);
		preOrder(root->right, d + 1);
	}


}
int main() {
	int n;

	scanf("%d", &n);
	while (n--) {
		int data[1000] = { 0 };
		int num, i = 0;
		while (scanf("%d", &num) && num != -1) {
			data[i] = num;
			i++;
		}
		struct TreeNode* root = buildTree(data, i, 0);
		printf("%d ", depth(root));
		preOrder(root, 1);
		printf("\n");
	}
	return 0;
}
///
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* createNode(int val) {

}






//email
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidEmail(char email[]) {
	int i, at_index = -1, dot_index = -1, length = strlen(email);

	if (length < 6) {
		return 0;
	}

	for (i = 0; i < length; i++) {

		if (email[i] == '@') {
			if (at_index != -1) { return 0; }
			at_index = i;
		}
		else if (email[i] == '.') {
			if (dot_index != -1) { return 0; }
			dot_index = i;
		}
		else if (!isalnum(email[i]) && email[i] != '_') {
			return 0;
		}
	}

	if (at_index == -1 || dot_index == -1 || at_index > dot_index) {
		return 0;
	}

	if (!isalnum(email[at_index - 1]) || !isalnum(email[at_index + 1])) {
		return 0;
	}

	if (strcmp(email + dot_index + 1, "com") != 0) {
		return 0;
	}

	return 1;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char email[100];
		scanf("%s", email);

		if (isValidEmail(email)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}


int main() {
	int n;
	int a[100] = {-1};
	char exe[5];
	int top=0;
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", exe);
		if (strcmp(exe, "pop") == 0) {
			if (top == 0) { printf("%s\n", "empty"); }
			else { printf("%d\n", a[top - 1]); top--; }
		}
		if (strcmp(exe, "push") == 0) {
			scanf("%d", &a[top]);
			top++;
		}
	}
	return 0;
}
int main() {
	char a[1000];
	char ans[1000];
	int cnt=0;
	gets(a);
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] != '#' && a[i] != '@') {
			ans[cnt] = a[i];
			cnt++;
		}
		else {
			if (a[i] == '#') {
				cnt--;
			}
			if (a[i] == '@') {
				cnt=0;
				strcpy(ans, "");
			}
		}
	}
	ans[cnt] = '\0';
	printf("%s\n", ans);

	return 0;
}

//
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
	stack[++top] = x;
}

void pop() {
	--top;
}

void printStack() {
	int i;
	for (i = 0; i < top; ++i) {
		printf("%d ", stack[i]);
	}
	printf("%d\n\n", stack[i]);
}

void findCombination(int n, int maxNum) {
	if (n == 0) {
		printStack();
		return;
	}

	for (int i = maxNum; i > 0; --i) {
		if (n - i >= 0) {
			push(i);
			findCombination(n - i, i - 1);  // i-1保证数字只被使用一次且降序排列
			pop();
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	findCombination(n, n);
	return 0;
}
//1871
#include <stdio.h>

int isUgly(int num) {
	if (num <= 0) {
		return 0;
	}

	while (num % 2 == 0) {
		num /= 2;
	}
	while (num % 3 == 0) {
		num /= 3;
	}
	while (num % 5 == 0) {
		num /= 5;
	}

	return num == 1;
}

int main() {
	int n;
	scanf("%d", &n);

	if (isUgly(n)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}


int main() {
	int a[1000], b[1000], na=0, nb=0;
	int i = 1, n = 1,len,j;
	scanf("i=%d,len=%d,j=%d", &i, &len, &j);
	scanf("%d", &a[na]);
	while (a[na] != -1) {
		na++;
		scanf("%d", &a[na]);
	}
	scanf("%d", &b[nb]);
	while (b[nb] != -1) {
		nb++;
		scanf("%d", &b[nb]);
	}
	for (n = 0; n < nb-1; n++) {
		if (n == j-1) {
			for (int ja = 0; ja < na;ja++) {
				// ja = i - 1; ja < i + len - 1;
				if (ja >= i - 1 && ja < i + len - 1) { continue; }
				else{printf("%d ", a[ja]);}
			}
		}
		printf("%d ", b[n]);
	}
	printf("%d\n", b[n]);
}


//1743
int main() {
	int a[1000], b[1000], na=0, nb=0;
	int i = 1, n = 1,len,j;
	scanf("i=%d,len=%d,j=%d", &i, &len, &j);
	scanf("%d", &a[na]);
	while (a[na] != -1) {
		na++;
		scanf("%d", &a[na]);
	}
	scanf("%d", &b[nb]);
	while (b[nb] != -1) {
		nb++;
		scanf("%d", &b[nb]);
	}
	for (n = 0; n < nb-1; n++) {
		if (n == j-1) {
			for (int ja = 0; ja < na;ja++) {
				// ja = i - 1; ja < i + len - 1;
				if (ja >= i - 1 && ja < i + len - 1) { continue; }
				else{printf("%d ", a[ja]);}
			}
		}
		printf("%d ", b[n]);
	}
	printf("%d\n", b[n]);
}

//1754快速排序
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int a[10000];
void sort(int low, int high) {
	int f = low, g = high;
	if (low < high) {
		a[0] = a[high];
		while (low < high) {
			// while(low<high&&a[low]<=a[0]) ++low;
			while (low < high && a[low] < a[0]) ++low;
			a[high] = a[low];  if (low < high)high--;
			// while(low<high&&a[high]>=a[0]) --high;
			while (low<high && a[high]> a[0]) --high;
			a[low] = a[high];  if (low < high)low++;
		}
		a[low] = a[0];
		//sort(f,low-1);
		//sort(low+1,g);
	}
}
int main() {
	int i = 1, n = 1;
	while (scanf("%d", &a[n]) != EOF) {
		if (a[n] != -1) n++;
		else {
			sort(1, n - 1);
			for (i = 1; i < n - 1; i++) printf("%d ", a[i]);
			printf("%d\n", a[i]);
			n = 1;
		}
	}
}

///1740
int main() {
	int i, j,m,n;
	char a[3000];
	scanf("i=%d,j=%d\n", &i, &j);
	gets(a);
	if (j > strlen(a)) { j = strlen(a); }
	if ((i + j) % 2 == 0) {
		m = (i + j) / 2 - 1-1;
		n = (i + j) / 2 + 1-1;
	}
	else {
		m = (i + j - 1) / 2-1;
		n = (i + j + 1) / 2-1;
	}
	int flag = 1;
	while (n >= i) {
		if (a[n] == a[m]) {
			n--; m++;
			//printf("%c%c\n", a[n], a[m]);
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}

//1738
int main() {
	int a[1000], n,mind=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[mind] > a[i]) { mind = i; }
	}
	//qsort(a, n, sizeof(int), comp);
	for (int i = mind; i > 0; i--) {
		swap(&a[i], &a[i - 1]);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}


//1727
int main() {
	int a[1000], b[1000], c[30005] = {0};

	int n,m,x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		c[b[i]]++;
	}
	//qsort(a, n, sizeof(int), comp);

	int i = 0; int j = 0;
	for(i=0;i<30005;i++){
		if (c[i] > 0) { printf("%d ", i); }
	}
	return 0;
}
///1725
int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
int main() {
	int a[1000],b[20050];
	int n,x;
	for (int i=0; i < 20001; i++) { b[i] = 0; }
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	scanf("%d", &x);
	//qsort(a, n, sizeof(int), comp);
	int cnt = 0;
	for (int i =20000; i > x; i--) {
		if (b[i]>0) { cnt++; }
	}
	printf("%d\n", cnt);
	for (int i =x-1; i >=0; i--) {
		if (b[i]>0) { printf("%d ", i); }
	}

	return 0;
}

//
int main() {
	char a[1000],b[1000];
	strcpy(b, "");
	gets(a);
	sprintf(b, "%s", strcat(b, a));
	gets(a);
	sprintf(b, "%s", strcat(b, a));
	puts(b);
}

//1780//
int main() {

	char s[1000];
	char t[1000];
	char f[1000];
	char ans[1000];
	char tmpc[1000];
	int tmp = 0;
	int flag = 0;
	scanf("%s%s%s", s, t, f);
	strcpy(ans, "");
	strcpy(tmpc, "");
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] != t[tmp]) {
			if (tmp != 0) {
				sprintf(ans, "%s%s", ans, tmpc);
				strcpy(tmpc, "");
				tmp = 0;
				i--;
				continue;
			}

			sprintf(ans, "%s%c", ans,s[i]);

		}
		else {
			if (tmp != strlen(t) - 1) {
				sprintf(tmpc, "%s%c", tmpc,s[i]);
				tmp++;
			}
			else {
				sprintf(ans, "%s%s",ans, f);
				flag = 1;
				tmp = 0;
				strcpy(tmpc, "");
			}
		}
	}
	if (flag) {
		printf("%s", ans);
	}
	else {
		printf("NO\n");
	}

}

//fgets(expression, sizeof(expression), stdin);
//char a[1000];
sprintf(a, "%s", "abc");


//1741
int main() {
	int n, i, j, cnt = 0;
	int a[3000], b[20000];
	for (i = 0; i < 20000; i++) {
		b[i] = 0;
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			b[a[i]] ++ ;
			cnt++;
		}
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			b[a[i]] ++;
			cnt++;
		}
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			b[a[i]] ++;
			cnt++;
		}
	}


	for (i = 0; i <20000; i++) {
		if(b[i]==3) {
			printf("%d ",i);
		}
	}

	return 0;
}

///1724
int main() {
	int n,i,j,cnt=0;
	int a[3000],b[2000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			b[cnt] = a[i];
			cnt++;
		}
	}
	for (i = 0; i < cnt; i++) {
		printf("%d ", b[i]);
	}

	return 0;
}
///1749//
int main() {
	int a[100], na = 0;
	int b[100], nb = 0;
	int tmp = 0;
	char tmpc;

	scanf("A序列为 %d%c", &tmp, &tmpc);
	while (tmpc != '\n') {
		a[na] = tmp;
		na++;
		scanf("%d%c", &tmp,&tmpc);
	}
	getchar();
	scanf("B序列为 %d%c", &tmp, &tmpc);
	while (tmpc != '\n') {
		b[nb] = tmp;
		nb++;
		scanf("%d%c", &tmp, &tmpc);
	}

	int cnt = 0;
	int flag = 0,flag2=1;
	for (int i = 0; i < nb; i++) {
		for (int j = 0; j < na; j++) {
			if (a[j] == b[i]) { flag = 1; break; }
		}
		if (flag) {
			cnt++;
		}
		else {
			flag2 = 0;
			break;
		}
	}
	if (flag2) {
		printf("是\n");
	}
	else {
		printf("否\n");
	}
	return 0;
}


int main() {
	int a[1000];
	int n, i, j;
	scanf("输入线性表的节点数N=%d；", &n);
	int flag = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i > 0) {
			if (a[i] != (i + 1) * (i + 1) - a[i - 1]) {
				flag = 0;
			}
		}
	}
	if (flag) { printf("true\n"); }
	else { printf("false\n"); }

	return 0;
}

//compare
int main() {
	int a[100], na = 0;
	int b[100], nb = 0;
	int tmp = 0;

	scanf("%d", &tmp);
	while (tmp != -1) {
		a[na] = tmp;
		na++;
		scanf("%d", &tmp);
	}
	scanf("%d", &tmp);
	while (tmp != -1) {
		b[nb] = tmp;
		nb++;
		scanf("%d", &tmp);
	}
	int cnt = 0;
	for (int i = 0; i < na; i++) {
		int flag = 1;
		for (int j = 0; j < nb; j++) {
			if (a[i] == b[j]) { flag = 0; break; }
		}
		if (flag) {
			printf("%d ", a[i]);
			cnt++;
		}
	}
	printf("\n%d", cnt);
	return 0;
}

int main() {
	int a[100];
	int n, i, j,k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for (i = 0; i < n; i++) {
		if(a[i]!=k) {
			printf("%d ", a[i]);
		}
	}
	//printf("%d\n", a[i]);

	return 0;
}


int main() {
	int a[100],na=0;
	int b[100],nb=0;
	int tmp = 0;

	scanf("%d", &tmp);
	while (tmp != -1) {
		a[na] = tmp;
		na++;
		scanf("%d", &tmp);
	}
	scanf("%d", &tmp);
	while (tmp != -1) {
		b[nb] = tmp;
		nb++;
		scanf("%d", &tmp);
	}
	int cnt = 0;
	for (int i = 0; i < na; i++) {
		int flag = 1;
		for (int j = 0; j < nb; j++) {
			if (a[i] == b[j]) { flag = 0; break; }
		}
		if (flag) {
			printf("%d ", a[i]);
			cnt++;
		}
	}
	printf("\n%d", cnt);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const char* p;
double e1();

double getnum() {
	double num = 0;
	while (isdigit(*p)) {
		num = num * 10 + *p - '0';
		p++;
	}
	return num;
}

double e3() {
	if (*p == '(') {
		p++;
		double ans = e1();
		if (*p == ')') {
			p++;
			return ans;
		}
	}
	return getnum();
}

double e2() {
	double left = e3();
	while (*p == '*' || *p == '/') {
		char op = *p++;
		double right = e3();
		if (op == '*') {
			left = left * right;
		}
		if (op == '/') {
			left = left / right;
		}

	}
	return left;
}
double e1() {
	double left = e2();
	while (*p == '+' || *p == '-') {
		char op = *p++;
		double right = e2();
		if (op == '+') {
			left = left + right;
		}
		if (op == '-') {
			left = left - right;
		}

	}
	return left;
}

int main() {
	char exp[200];
	while (fgets(exp,sizeof(exp),stdin)) {
		p = exp;
		double ans = e1(exp);
		printf("%.3f\n", ans);
	}
	return 0;
}



//parse expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const char* p;
double e1();

double getnum() {
	double num = 0;
	while (isdigit(*p)) {
		num = num * 10 + *p - '0';
		p++;
	}
	return num;
}

double e3() {
	if (*p == '(') {
		p++;
		double ans = e1();
		if (*p == ')') {
			p++;
			return ans;
		}
	}
	return getnum();
}

double e2() {
	double left = e3();
	while (*p == '*' || *p == '/') {
		char op = *p++;
		double right = e3();
		if (op == '*') {
			left = left * right;
		}
		if (op == '/') {
			left = left / right;
		}

	}
	return left;
}
double e1() {
	double left = e2();
	while (*p == '+' || *p == '-') {
		char op = *p++;
		double right = e2();
		if (op == '+') {
			left = left + right;
		}
		if (op == '-') {
			left = left - right;
		}

	}
	return left;
}

int main() {
	char exp[200];
	while (fgets(exp,sizeof(exp),stdin)) {
		p = exp;
		double ans = e1(exp);
		printf("%.3f\n", ans);
	}
	return 0;
}


*/




///1814
#include <stdio.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

int depth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);
	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void preOrder(struct TreeNode* root,int d) {
	int dep=d;
	if (root != NULL) {
		if(dep==1){ printf("%d", root->val); }
		else { printf(" %d", root->val); }
		preOrder(root->left,dep+1);
		preOrder(root->right,dep+1);
	}
}

struct TreeNode* buildTree(int* data, int len, int index) {
	if (index < len && data[index] != 0) {
		struct TreeNode* root = createNode(data[index]);
		root->left = buildTree(data, len, index * 2 + 1);
		root->right = buildTree(data, len, index * 2 + 2);
		return root;
	}
	return NULL;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int data[1000] = { 0 };
		int num, i = 0;
		while (scanf("%d", &num) && num != -1) {
			data[i++] = num;
		}

		struct TreeNode* root = buildTree(data, i, 0);
		printf("%d ", depth(root));
		preOrder(root,1);
		printf("\n");
	}
	return 0;
}

///152G///
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct {
    int val;
    int pos;
} Card;

int cmp(const void *a, const void *b) {
    return ((Card *)a)->val - ((Card *)b)->val;
}

int main() {
    int n, i;
    while (scanf("%d", &n) != EOF) {
        Card cards[MAX_N];
        int visited[MAX_N] = {0};
        for (i = 0; i < n; ++i) {
            scanf("%d", &cards[i].val);
            cards[i].pos = i;
        }
        qsort(cards, n, sizeof(Card), cmp);
        int swaps = 0;
        for (i = 0; i < n; ++i) {
            if (visited[i] || cards[i].pos == i)
                continue;
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = 1;
                j = cards[j].pos;
                cycle_size++;
            }
            if (cycle_size > 0)
                swaps += cycle_size - 1;
        }
        printf("%d\n", swaps);
    }
    return 0;
}

///151E
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d,i,k[1000],j;
    while (scanf("%d", &k[0]) != EOF) {
        b = 1;
        while (1) {
            scanf("%d", &k[b]);
            if (k[b] == -1)break;
            b++;
        }
        int high = b - 1, low = 0;
        j = k[b - 1];
        int t = 50;
        while (t--) {
            for (a = low; a < b ; a++) {
                if (k[a] >= j) {
                    low = a;
                    k[high] = k[a];
                    break;
                }
            }
            for (a = high-1; a >= 0; a--) {
                if (k[a] <= j) {
                    high = a;
                    k[low] = k[a];
                    break;
                }
            }
            if (high <= low) { 
                k[low] = j;
                break; 
            }
        
        }
        for (a = 0; a < b-1; a++) {
            printf("%d ", k[a]);
        }
        printf("%d\n", k[a]);
    }
    return 0;
}
////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* p;

double parse_expression();

double parse_number() {
	double num = 0;
	while (isdigit(*p)) {
		num = num * 10 + *p - '0';
		p++;
	}
	return num;
}

double parse_parenthesis() {
	if (*p == '(' ||*p =='[') {
		p++;
		double result = parse_expression();
		if (*p == ')' ||*p ==']') {
			p++;
			return result;
		}
	}
	return parse_number();
}

double parse_term() {
	double left = parse_parenthesis();
	while (*p == '*' || *p == '/') {
		char op = *p++;
		double right = parse_parenthesis();
		if (op == '*') {
			left *= right;
		}
		else {
			left /= right;
		}
	}
	return left;
}

double parse_expression() {
	double left = parse_term();
	while (*p == '+' || *p == '-') {
		char op = *p++;
		double right = parse_term();
		if (op == '+') {
			left += right;
		}
		else {
			left -= right;
		}
	}
	return left;
}

int main() {
	char expression[1001];
	int n;
	scanf("%d",&n);
	for(int i;i<n;i++){
		fgets(expression, sizeof(expression), stdin);
		p = expression;
		double result = parse_expression();
		printf("%g\n", result);
	}
	
	return 0;
}



//152D
#include<stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int arr[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        insertion_sort(arr, n);
        print_array(arr, n);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct {
	int val;
	int pos;
} Card;

int cmp(const void* a, const void* b) {
	return ((Card*)a)->val - ((Card*)b)->val;
}

int main() {
	int n, i;
	while (scanf("%d", &n) != EOF) {
		Card cards[MAX_N];
		int visited[MAX_N] = { 0 };
		for (i = 0; i < n; ++i) {
			scanf("%d", &cards[i].val);
			cards[i].pos = i;
		}
		qsort(cards, n, sizeof(Card), cmp);
		int swaps = 0;
		for (i = 0; i < n; ++i) {
			if (visited[i] || cards[i].pos == i)
				continue;
			int cycle_size = 0;
			int j = i;
			while (!visited[j]) {
				visited[j] = 1;
				j = cards[j].pos;
				cycle_size++;
			}
			if (cycle_size > 0)
				swaps += cycle_size - 1;
		}
		printf("%d\n", swaps);
	}
	return 0;
}



//152F
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[11];
	int score;
} Contestant;

int cmp(const void* a, const void* b) {
	Contestant* c1 = (Contestant*)a;
	Contestant* c2 = (Contestant*)b;
	if (c2->score != c1->score)
		return c2->score - c1->score;
	return strcmp(c1->name, c2->name);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int weight[3005];
	for (int i = 0; i < m; i++) {
		scanf("%d", &weight[i]);
	}
	Contestant contestants[1005];
	for (int i = 0; i < n; i++) {
		scanf("%s", contestants[i].name);
		int total = 0;
		for (int j = 0; j < m; j++) {
			int score;
			scanf("%d", &score);
			total += score * weight[j];
		}
		contestants[i].score = total;
	}
	qsort(contestants, n, sizeof(Contestant), cmp);
	for (int i = 0; i < n; i++)
		printf("%s\n", contestants[i].name);
	return 0;
}

//152E
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[101];
	double score;
} Student;

int cmp(const void* a, const void* b) {
	Student* s1 = (Student*)a;
	Student* s2 = (Student*)b;
	if (s2->score != s1->score)
		return s2->score > s1->score ? 1 : -1;
	return strcmp(s1->name, s2->name);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int credit[3005];
		int sum = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &credit[i]);
			sum += credit[i];
		}
		Student students[1005];
		for (int i = 0; i < n; i++) {
			scanf("%s", students[i].name);
			double total = 0;
			for (int j = 0; j < m; j++) {
				int grade;
				scanf("%d", &grade);
				total += grade * credit[j];
			}
			students[i].score = total / sum;
		}
		qsort(students, n, sizeof(Student), cmp);
		for (int i = 0; i < n; i++)
			printf("%s\n", students[i].name);
		printf("\n");
	}
	return 0;
}

//152D

#include <stdio.h>

int main() {
	int a, b, c, temp;

	scanf("%d %d %d", &a, &b, &c);

	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c) {
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c) {
		temp = b;
		b = c;
		c = temp;
	}

	printf("%d %d %d\n", a, b, c);
	return 0;
}

//152C
#include <stdio.h>

#define MAX 10
#define DIGITS 3

void radixsort(int A[], int n) {
	int i, m = 0, exp = 1;
	int bucket[1000], temp[MAX];
	for (i = 0; i < n; i++) {
		if (A[i] > m)
			m = A[i];
	}

	while (m / exp > 0) {
		for (i = 0; i < MAX; i++)
			temp[i] = 0;

		for (i = 0; i < n; i++)
			temp[(A[i] / exp) % 10]++;

		for (i = 1; i < MAX; i++)
			temp[i] += temp[i - 1];

		for (i = n - 1; i >= 0; i--)
			bucket[--temp[(A[i] / exp) % 10]] = A[i];

		for (i = 0; i < n; i++)
			A[i] = bucket[i];
		exp *= 10;

		for (i = 0; i < n-1; i++)
			printf("%d ", A[i]);
		printf("%d\n", A[i]);
	}
}

int main() {
	int n;
	while (scanf("%d", &n), n != -1) {
		int A[1000];
		int i = 0;
		A[i++] = n;
		while (scanf("%d", &n), n != -1) {
			A[i++] = n;
		}
		radixsort(A, i);
	}
	return 0;
}

//152A
#include <stdio.h>
void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n-1; ++i) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[i]);
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void buildHeap(int arr[], int n) {
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void heapSort(int arr[], int n) {
	buildHeap(arr, n);
	printArray(arr, n);

	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
		printArray(arr, n);
	}
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int arr[1000];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		heapSort(arr, n);
	}
	return 0;
}

//151G
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int DNAnum;
	char str[52];
}NodeDNA;

int DNAcount(char* destination, int len)
{
	
int iterX = 0;
int iterY = 0;
int cnt = 0;
for (iterX = 0; iterX < len - 1; iterX++)
{
	if (destination[iterX] == 'A')
	{
		continue;
	}
	for (iterY = iterX + 1; iterY < len; iterY++)
	{
		if (destination[iterX] > destination[iterY])
		{
			cnt++;
		}
	}
}
return cnt;
}

int cmp(const void* a, const void* b)
{
	NodeDNA* x = (NodeDNA*)a;
	NodeDNA* y = (NodeDNA*)b;
	return (x->DNAnum) - (y->DNAnum);
}

int main(void)
{
	NodeDNA NoDNA[101];
	int col = 0;
	int row = 0;
	int iter = 0;
	//scanf("%d%d", &col, &row);
	//fflush(stdin);
	while (scanf("%d%d", &col, &row) != EOF)
	{
		getchar();
		for (iter = 0; iter < row; iter++)
		{
			gets(NoDNA[iter].str);
			NoDNA[iter].DNAnum = DNAcount(NoDNA[iter].str, col);
		}
		qsort(NoDNA, row, sizeof(NodeDNA), cmp);
		for (iter = 0; iter < row; iter++)
		{
			puts(NoDNA[iter].str);
		}
	}

	return 0;
}

//151F
#include <stdio.h>

#include <stdio.h>

void merge(int A[], int m, int B[], int n, int C[]) {
	int i = 0, j = 0, k = 0;

	// Merge the two arrays while maintaining the sorted order
	while (i < m && j < n) {
		if (A[i] <= B[j]) {
			C[k++] = A[i++];
		}
		else {
			C[k++] = B[j++];
		}
	}

	// Copy the remaining elements of A, if any
	while (i < m) {
		C[k++] = A[i++];
	}

	// Copy the remaining elements of B, if any
	while (j < n) {
		C[k++] = B[j++];
	}
}

int main() {
	int A[1000], B[1000], C[2000], m, n, i;

	while (scanf("%d", &m) != EOF) {
		for (i = 0; i < m; i++) {
			scanf("%d", &A[i]);
		}

		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &B[i]);
		}

		merge(A, m, B, n, C);

		for (i = 0; i < m + n; i++) {
			printf("%d", C[i]);
			if (i != m + n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}

//151D//???

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int* arr = (int*)malloc(n * sizeof(int));

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		qsort(arr, n, sizeof(int), compare);

		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		free(arr);
	}

	return 0;
}

//151C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

void swap_parts(char* str, int mid) {
	int len = strlen(str);
	for (int i = 0; i < mid; i++) {
		char temp = str[i];
		str[i] = str[len - mid + i];
		str[len - mid + i] = temp;
	}
}

int main() {
	char str[101];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		int mid = len / 2;

		qsort(str, mid, sizeof(char), compare);
		swap_parts(str, mid);

		printf("%s\n", str);
	}
	return 0;
}

//151B
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int arr[1000];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		qsort(arr, n, sizeof(int), compare);

		int P = 0, Q = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				P += arr[i];
			}
			else {
				Q += arr[i];
			}
		}

		printf("%d\n", abs(P - Q));
	}
	return 0;
}

//142F
#include<stdio.h>

void checkWeek(char ch) {
	switch (ch) {
	case 'M': printf("Monday\n"); break;
	case 'W': printf("Wednesday\n"); break;
	case 'F': printf("Friday\n"); break;
	default: printf("Wrong data\n");
	}
}

int main() {
	char ch, next_ch;
	while ((ch = getchar()) != 'Y') {
		if (ch == 'S' || ch == 'T') {
			next_ch = getchar();
			if (ch == 'S') {
				if (next_ch == 'u') {
					printf("Sunday\n");
				}
				else if (next_ch == 'a') {
					printf("Saturday\n");
				}
				else {
					printf("Wrong data\n");
					ungetc(next_ch, stdin);  // push the character back to the input
				}
			}
			else if (ch == 'T') {
				if (next_ch == 'u') {
					printf("Tuesday\n");
				}
				else if (next_ch == 'h') {
					printf("Thursday\n");
				}
				else {
					printf("Wrong data\n");
					ungetc(next_ch, stdin);  // push the character back to the input
				}
			}
		}
		else {
			checkWeek(ch);
		}
	}
	return 0;
}

//142E/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double a[10000], b[10000], max = 0;
int t;

void vis(int x, int y, int z) {
	double l[10], sil, lr, len;
	int i, j;
	l[0] = pow(pow(fabs(a[x] - a[y]), 2) + pow(fabs(b[x] - b[y]), 2), 0.5);
	l[1] = pow(pow(fabs(a[x] - a[z]), 2) + pow(fabs(b[x] - b[z]), 2), 0.5);
	l[2] = pow(pow(fabs(a[y] - a[z]), 2) + pow(fabs(b[y] - b[z]), 2), 0.5);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (l[j] > l[j + 1])sil = l[j], l[j] = l[j + 1], l[j + 1] = sil;
		}
	}
	if (pow(l[0], 2) + pow(l[1], 2) < pow(l[2], 2))lr = l[2] / 2;
	else {
		len = (l[0] + l[1] + l[2]) / 2;
		lr = l[0] * l[1] * l[2] / (4 * pow(len * (len - l[0]) * (len - l[1]) * (len - l[2]), 0.5));
	}
	if (max < lr)max = lr;
}

void rase() {
	int x, y, z;
	for (x = 0; x < t; x++) {
		for (y = x + 1; y < t; y++) {
			for (z = y + 1; z < t; z++) {
				vis(x, y, z);
			}
		}
	}
	printf("%.4lf", max);
}

int main() {
	int i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lf,%lf", &a[i], &b[i]);
	}
	printf("以上%d个点的覆盖圆的最小半径为", t);
	if (t == 2)printf("%.4lf", pow(pow(a[0] - a[1], 2) + pow(b[0] - b[1], 2), 0.5) / 2);
	else if (t >= 3)rase();
}


//142C//
#include <stdio.h>
#include <stdlib.h>

void num2ip(unsigned int ip) {
	printf("%d.%d.%d.%d\n",
		(ip >> 24) & 0xFF,
		(ip >> 16) & 0xFF,
		(ip >> 8) & 0xFF,
		ip & 0xFF);
}

int main() {
	unsigned int ip;
	char input[9]; // 8 characters for 32-bit hex number, 1 character for string ending '\0'

	scanf("%8s", input);

	ip = strtoul(input, NULL, 16);

	num2ip(ip);

	return 0;
}
//142D//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int str2ip(const char* str) {
	unsigned int ip = 0;
	int segValue;
	int segCount = 0;

	while (*str) {
		segValue = 0;
		while (*str && *str != '.') {
			if (*str < '0' || *str > '9') {
				return 0; // Return 0 for error
			}
			segValue = segValue * 10 + (*str - '0');
			if (segValue > 255) {
				return 0; // Return 0 for error
			}
			++str;
		}

		ip = (ip << 8) | segValue;
		++segCount;

		if (*str) {
			++str; // Skip '.'
		}
	}

	if (segCount != 4) {
		return 0; // Return 0 for error
	}

	return ip;
}

int main() {
	char ipStr[101];
	unsigned int ip;

	scanf("%100s", ipStr);

	ip = str2ip(ipStr);

	if (ip) {
		printf("%u\n", ip);
		printf("%x\n", ip);
	}
	else {
		printf("error\n");
	}

	return 0;
}

//142B//
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int adjacencyMatrix[MAXN][MAXN];
int path[MAXN], pathTop;
int resultPath[MAXN], resultPathLength;
int numVertices, numEdges, maxPathWeight, pathWeightSum;

void dfs(int vertex) {
	int j;
	if (vertex == numVertices) {
		if (pathWeightSum > maxPathWeight) {
			maxPathWeight = pathWeightSum;
			resultPathLength = pathTop;
			for (j = 0; j < pathTop; j++)
				resultPath[j] = path[j];
		}
		return;
	}

	for (j = 1; j <= numVertices; j++) {
		if (adjacencyMatrix[vertex][j] > 0 && checkPath(j)) {
			path[pathTop++] = j;
			pathWeightSum += adjacencyMatrix[vertex][j];
			dfs(j);
			pathWeightSum -= adjacencyMatrix[vertex][j];
			pathTop--;
		}
	}
}

int checkPath(int vertex) {
	int j;
	for (j = 0; j < pathTop; j++) {
		if (path[j] == vertex)
			return 0;
	}
	return 1;
}

int main() {
	int i, j, x, y, z;
	while (scanf("%d%d", &numVertices, &numEdges) != EOF) {
		for (i = 1; i <= numVertices; i++) {
			for (j = 1; j <= numVertices; j++) {
				adjacencyMatrix[i][j] = 0;
				adjacencyMatrix[j][i] = 0;
			}
		}
		maxPathWeight = 0;
		pathTop = 0;
		pathWeightSum = 0;

		for (i = 0; i < numEdges; i++) {
			scanf("%d%d%d", &x, &y, &z);
			adjacencyMatrix[x][y] = z;
		}

		path[pathTop++] = 1;
		dfs(1);

		printf("%d\n", maxPathWeight);
		for (j = 0; j < resultPathLength - 1; j++)
			printf("%d %d\n", resultPath[j], resultPath[j + 1]);
	}
	return 0;
}

//142A
#include <stdio.h>
#include <string.h>

#define MAXN 1010

int n, m, t;
int g[MAXN][MAXN];
int vis[MAXN];

void dfs(int u) {
	vis[u] = 1;
	for (int v = 1; v <= n; v++)
		if (!vis[v] && g[u][v])
			dfs(v);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));

		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}

		dfs(1);
		int flag = 1;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				flag = 0;
				break;
			}
		if (flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

//141A
#include<stdio.h>
#include<stdlib.h>
int r[100][100];
int q[100], top;
char name[100], x; y;
int a, b;
int q1[100], q2[100], p1 = 0, p2 = 0;
void dfs(int i);
void dft1();
void dft2();
void dfs(int i) {
	int j;
	for (j = 1; j <= a; j++) {
		if (r[i][j] != 0 && sol(j) == 1) { q[top++] = j; dfs(j); }
	}
}

void dft1() {
	int i, j; p1 = 0;
	for (i = 0; i < p2; i++) {
		for (j = 1; j <= a; j++) {
			if (r[q2[i]][j] != 0 && sol(j) == 1) {
				q[top++] = j; q1[p1++] = j;
				if (q2[i] < j)printf("%c,%c\n", name[q2[i]], name[j]);
				else printf("%c,%c\n", name[j], name[q2[i]]);
			}
		}
	}
	if (p1 != 0)dft2();
}
void dft2() {
	int i, j; p2 = 0;
	for (i = 0; i < p1; i++) {
		for (j = 1; j <= a; j++) {
			if (r[q1[i]][j] != 0 && sol(j) == 1) {
				q[top++] = j; q2[p2++] = j;
				if (q1[i] < j)printf("%c,%c\n", name[q1[i]], name[j]);
				else printf("%c,%c\n", name[j], name[q1[i]]);
			}
		}
	}
	if (p2 != 0)dft1();
}

void vit() {
	int i, j;
	for (i = 1; i <= a; i++) {
		if (name[i] == x)break;
	}
	for (j = 1; j <= a; j++) {
		if (name[j] == y)break;
	}
	r[i][j] = 1; r[j][i] = 1;
}

int sol(int i) {
	int j;
	for (j = 0; j < top; j++) {
		if (q[j] == i)return 0;
	}
	return 1;
}

int main() {
	int c, d;
	scanf("%d", &a); top = 0;
	for (c = 1; c <= a; c++) { scanf(" %c", &name[c]); }
	for (c = 1; c <= a; c++)for (d = 1; d <= a; d++)r[c][d] = 0;
	scanf("%d", &b); getchar();
	for (c = 1; c <= b; c++) {
		scanf(" %c,%c", &x, &y); vit();
	}
	q[top++] = 1; dfs(1);
	if (top != a)printf("ERROR\n");
	else { top = 0; q[top++] = 1; q1[p1++] = 1; dft2(); }
}
//141B
int main() {
	int m, n;
	float ans;
	while (scanf("%d%d",&m,&n) != EOF) {
		if (m % 2 != 0 && n % 2 != 0) {
			ans = (m * n) - 1.00 + 1.41;
		}
		else {
			ans = m * n;
		}
		printf("%.2f\n", ans);
	}


	return 0;
}

//141C//
#include<stdio.h>
#include<stdlib.h>
int r[100][100];
int q[100], top;
char name[100], x; y;
int a, b;

void dfs(int i) {
	int j;
	for (j = 1; j <= a; j++) {
		if (r[i][j] != 0 && sol(j) == 1) { q[top++] = j; dfs(j); }
	}
}

void dft(int i) {
	int j;
	for (j = 1; j <= a; j++) {
		if (r[i][j] != 0 && sol(j) == 1) {
			q[top++] = j;
			if (i < j)printf("%c,%c\n", name[i], name[j]);
			else printf("%c,%c\n", name[j], name[i]); dft(j);
		}
	}
}

void vit() {
	int i, j;
	for (i = 1; i <= a; i++) {
		if (name[i] == x)break;
	}
	for (j = 1; j <= a; j++) {
		if (name[j] == y)break;
	}
	r[i][j] = 1; r[j][i] = 1;
}

int sol(int i) {
	int j;
	for (j = 0; j < top; j++) {
		if (q[j] == i)return 0;
	}
	return 1;
}
int main() {
	int c, d;
	scanf("%d", &a); top = 0;
	for (c = 1; c <= a; c++) { scanf(" %c", &name[c]); }
	for (c = 1; c <= a; c++)for (d = 1; d <= a; d++)r[c][d] = 0;
	scanf("%d", &b); getchar();
	for (c = 1; c <= b; c++) {
		scanf(" %c,%c", &x, &y); vit();
	}
	q[top++] = 1; dfs(1);
	if (top != a)printf("ERROR\n");
	else { top = 0; q[top++] = 1; dft(1); }
}


//141D
#include <stdio.h>
#include <string.h>
#define MAX_VERTEX 20
#define INF 0x3F3F3F3F

int graph[MAX_VERTEX][MAX_VERTEX];
int selected[MAX_VERTEX];
int min_weight[MAX_VERTEX];
int pre_vertex[MAX_VERTEX];
char vertex[MAX_VERTEX];
int v, e;

void prim() {
	min_weight[0] = 0;
	int totalWeight = 0;

	for (int i = 0; i < v; ++i) {
		int x = -1;
		for (int j = 0; j < v; ++j) {
			if (!selected[j] && (x == -1 || min_weight[j] < min_weight[x])) {
				x = j;
			}
		}
		if (i > 0 && min_weight[x] == INF) {
			printf("ERROR\n");
			return;
		}

		if (i > 0) {
			if (pre_vertex[x] < x) {
				printf("%c,%c:%d\n", vertex[pre_vertex[x]], vertex[x], min_weight[x]);
			}
			else {
				printf("%c,%c:%d\n", vertex[x], vertex[pre_vertex[x]], min_weight[x]);
			}
			totalWeight += min_weight[x];
		}

		selected[x] = 1;
		for (int y = 0; y < v; ++y) {
			if (graph[x][y] < min_weight[y]) {
				min_weight[y] = graph[x][y];
				pre_vertex[y] = x;
			}
		}
	}

	printf("\n%d\n", totalWeight);
}

int main() {
	scanf("%d", &v);
	getchar();
	for (int i = 0; i < v; ++i) {
		scanf("%c ", &vertex[i]);
	}
	scanf("%d", &e);
	getchar();
	for (int i = 0; i < v; ++i) {
		min_weight[i] = INF;
		for (int j = 0; j < v; ++j) {
			graph[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 0; i < e; ++i) {
		char start, end;
		int weight;
		scanf("%c,%c:%d", &start, &end, &weight);
		getchar();
		graph[start - 'A'][end - 'A'] = weight;
		graph[end - 'A'][start - 'A'] = weight;
	}
	prim();
	return 0;
}

//141E//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGE 100
#define MAX_VERTEX 20

typedef struct Edge {
	char start, end;
	int weight;
} Edge;

Edge edge[MAX_EDGE];
char vertex[MAX_VERTEX];
int parent[MAX_VERTEX];
int v, e;

int cmp(const void* a, const void* b) {
	return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int kruskal() {
	int totalWeight = 0;
	qsort(edge, e, sizeof(Edge), cmp);
	for (int i = 0; i < e; ++i) {
		int x = find(edge[i].start - 'A');
		int y = find(edge[i].end - 'A');
		if (x != y) {
			printf("%c,%c:%d\n", edge[i].start, edge[i].end, edge[i].weight);
			totalWeight += edge[i].weight;
			parent[y] = x;
		}
	}
	for (int i = 1; i < v; ++i) {
		if (find(i) != find(i - 1)) return -1;
	}
	return totalWeight;
}

int main() {
	scanf("%d", &v);
	getchar();
	for (int i = 0; i < v; ++i) {
		scanf("%c ", &vertex[i]);
		parent[i] = i;
	}
	scanf("%d", &e);
	getchar();
	for (int i = 0; i < e; ++i) {
		scanf("%c,%c:%d", &edge[i].start, &edge[i].end, &edge[i].weight);
		getchar();
	}
	int res = kruskal();
	if (res == -1) printf("ERROR\n");
	else {
		printf("\n%d\n", res);
	}
	return 0;
}
//141F
#include <stdio.h>
#define MAX_SIZE 200
#define INF 2000*MAX_SIZE

int graph[MAX_SIZE + 1][MAX_SIZE + 1];
int dist[MAX_SIZE + 1];
int visited[MAX_SIZE + 1];

void Dijkstra(int s, int n) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = graph[s][i];
	}
	visited[s] = 1;
	for (int i = 1; i <= n; ++i) {
		int minDist = INF;
		int minIndex;
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dist[j] < minDist) {
				minDist = dist[j];
				minIndex = j;
			}
		}
		visited[minIndex] = 1;
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dist[j] > graph[minIndex][j] + minDist) {
				dist[j] = graph[minIndex][j] + minDist;
			}
		}
	}
}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int i, j;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i == j) {
					graph[i][j] = 0;
				}
				else {
					graph[i][j] = INF;
				}
			}
		}

		for (i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (graph[a][b] > c) {  // If multiple edges, keep the shortest one
				graph[a][b] = c;
				graph[b][a] = c;
			}
		}

		int s, t;
		scanf("%d %d", &s, &t);

		for (i = 1; i <= n; ++i) {
			dist[i] = INF;
			visited[i] = 0;
		}

		Dijkstra(s, n);

		if (dist[t] == INF) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dist[t]);
		}
	}

	return 0;
}
//132B//
#include <stdio.h>
#include <string.h>
#define MAXLEN (1000 + 1)  //定义主串和模式的最大长度为1000

void CalcKMPNext(char t[], int next[]) {
	int j = 1, k = 0;
	next[1] = 0;  //根据next函数定义
	while (j < t[0])  //t[0]为模式的串长
	{
		//t[j]和t[k]分别表示后缀和前缀的单个字符，注意逻辑短路现象
		if (k == 0 || t[j] == t[k]) {
			j++;
			k++;
			next[j] = k;  //存入数组next
		}
		else k = next[k];  //若字符不相等，则k值回溯
	}
}

int main() {
	char t[MAXLEN];
	int next[MAXLEN];

	// 输入字符串
	scanf("%s", t + 1);  //模式串值复制到t+1指示的地址，t为数组首地址

	t[0] = strlen(t + 1);  //t[0]存储模式t的长度
	CalcKMPNext(t, next);  //计算next数组值

	// 输出next值
	for (int i = 1; i < t[0]; i++) {
		printf("%d ", next[i]);
	}
	printf("%d\n", next[t[0]]);

	return 0;
}
//132F//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[100];
	char delim[] = "`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/? ";

	fgets(str, sizeof(str), stdin);

	// remove trailing newline character
	str[strcspn(str, "\n")] = '\0';

	char* token = strtok(str, delim);

	while (token) {
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return 0;
}


//132E//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char input_string[100];
	char* decimal_point_location;
	int round_up_indicator, i;

	while (scanf("%s", input_string) != EOF) {
		decimal_point_location = strstr(input_string, ".");

		if (decimal_point_location == NULL) {
			printf("%s.00\n", input_string);
		}
		else {
			round_up_indicator = 0;

			if (*(decimal_point_location + 3) > '4') {
				round_up_indicator = 1;
				
				for (i = decimal_point_location - input_string + 2; i >= 0; i--) {
					if (input_string[i] == '.') continue;
					input_string[i] += round_up_indicator;
					
					if (input_string[i] <= '9') {
						round_up_indicator = 0;
						break;
					}
					else {
						input_string[i] = '0';
					}
				}
			}
			*(decimal_point_location + 3) = '\0';
		
			if (round_up_indicator == 0) {
				printf("%s\n", input_string);
			}
			else {
				printf("1%s\n", input_string);
			}
		}
		printf("\n");
	}
	return 0;
}



//132D
#include <stdio.h>
#include <string.h>

void getNext(char* pattern, int next[], int len) {
	int j = 0, k = -1;
	next[0] = -1;
	while (j < len - 1) {
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			if (pattern[j] != pattern[k]) {
				next[j] = k;
			}
			else {
				next[j] = next[k];
			}
		}
		else {
			k = next[k];
		}
	}
}

int KMP(char* text, char* pattern, int* matchCount) {
	int n = strlen(text);
	int m = strlen(pattern);
	int next[105];
	getNext(pattern, next, m);
	int i = 0, j = 0;
	*matchCount = 0;
	while (i < n && j < m) {
		if (j == -1 || text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			(*matchCount)++;
			j = next[j];
		}
	}
	if (j == m) {
		return i - j;
	}
	return -1;
}

int main() {
	char text[100];
	char pattern[100];
	scanf("%s", text);
	scanf("%s", pattern);
	int matchCount;
	int position = KMP(text, pattern, &matchCount);
	if (position >= 0) {
		printf("%d %d\n", matchCount + 1, position+1);
	}
	else {
		printf("0\n");
	}
	return 0;
}
//132C
#include <stdio.h>
#include <string.h>

void getNext(char* pattern, int next[], int len) {
	int j = 0, k = -1;
	next[0] = -1;
	while (j < len - 1) {
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			if (pattern[j] != pattern[k]) {
				next[j] = k;
			}
			else {
				next[j] = next[k];
			}
		}
		else {
			k = next[k];
		}
	}
}

int KMP(char* text, char* pattern) {
	int n = strlen(text);
	int m = strlen(pattern);
	int next[105];
	getNext(pattern, next, m);
	int i = 0, j = 0;
	int matchCount = 0;
	while (i < n && j < m) {
		if (j == -1 || text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			matchCount++;
			j = next[j];
		}
	}
	if (j == m) {
		return matchCount + 1;
	}
	return 0;
}

int main() {
	char text[100];
	char pattern[100];
	scanf("%s", text);
	scanf("%s", pattern);
	int matchCount = KMP(text, pattern);
	printf("%d\n", matchCount);
	return 0;
}
//132A//
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key, int* count) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		(*count)++;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] > key) {
			return binarySearch(arr, left, mid - 1, key, count);
		}
		return binarySearch(arr, mid + 1, right, key, count);
	}
	return -1;
}

int main() {
	int T, key, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &key, &n);
		int arr[105];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int count = 0;
		int result = binarySearch(arr, 0, n - 1, key, &count);
		if (result != -1) {
			printf("%d\n", count);
		}
		else {
			printf("Not Found\n");
		}
	}
	return 0;
}
//131F
#include<stdio.h>
#include<stdlib.h>
int r[1000][1000], rs[1000];
int q[1000], top, ne;
int a, b;

void dfs(int i) {
	int j;
	for (j = 1; j <= a; j++) {
		if (r[i][j] > 0 && sol(j) == 1) { q[top++] = j; dfs(j); }
	}
}

int sol(int i) {
	int j;
	for (j = 0; j < top; j++) {
		if (q[j] == i)return 0;
	}
	return 1;
}

int add(int i) {
	int j, sum;
	for (j = 1; j <= a; j++) {
		sum += r[i][j];
	}return sum;
}

int main() {
	int i, j, x, y, th, n[1000], flag;

	while (scanf("%d%d", &a, &b), a != 0) {

		for (i = 1; i <= a; i++) {
			for (j = 1; j <= a; j++) {
				r[i][j] = 0; r[j][i] = 0;
			}
		}top = 0; ne = -1; flag = 0;
		for (i = 0; i < b; i++) {
			scanf("%d%d", &x, &y);
			r[x][y]++, r[y][x]++;
		}
		for (i = 1; i <= a; i++) {
			if (add(i) == 0)continue;
			if (sol(i) == 1) { q[top++] = i; ne++; dfs(i); }
		}
		if (ne == 0) {
			for (i = 1; i <= a; i++) { n[i] = 0; }
			for (i = 1; i <= a; i++) {
				for (j = 1; j <= a; j++) {
					n[i] = n[i] + r[i][j];
				}
			}
			for (i = 1; i <= a; i++) {
				if (n[i] % 2 == 1)flag = 1;
			}
			if (flag == 1)printf("NO\n");
			else printf("YES\n");
		}
		else printf("NO\n");
	}
}




//131E/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

typedef struct edge {
	int u, v, w;
} Edge;

int parent[MAXN];
Edge edges[MAXN * MAXN / 2];

int cmp(const void* a, const void* b) {
	return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

int main() {
	int N;
	while (scanf("%d", &N), N) {
		int edgeNum = N * (N - 1) / 2;
		for (int i = 0; i < edgeNum; i++) {
			scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
		}
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		qsort(edges, edgeNum, sizeof(Edge), cmp);
		int total = 0;
		for (int i = 0; i < edgeNum; i++) {
			int u = find(edges[i].u), v = find(edges[i].v);
			if (u != v) {
				parent[u] = v;
				total += edges[i].w;
			}
		}
		printf("%d\n", total);
	}
	return 0;
}


//131D//

#include <stdio.h>
#include <string.h>

#define MAXN 1000

int graph[MAXN][MAXN];
int visited[MAXN];
int N, M;

void DFS(int node) {
	visited[node] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[node][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	while (scanf("%d", &N), N) {
		scanf("%d", &M);
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		int u, v;
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &u, &v);
			graph[u][v] = graph[v][u] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				DFS(i);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}

////131B///
#include<stdio.h>
#include<stdlib.h>
int r[1000][1000],rs[1000];
int q[1000],top,ne;
int a,b;

void dfs(int i){
int j;
for(j=1;j<=a;j++){
if(r[i][j]>0&&sol(j)==1){q[top++]=j;dfs(j);}}}

int sol(int i){
int j;
for(j=0;j<top;j++){
if(q[j]==i)return 0;}
return 1;}

int add(int i){
int j,sum;
for(j=1;j<=a;j++){
sum+=r[i][j];}return sum;}

int main(){
int i,j,x,y,th,n[1000],flag;
scanf("%d",&th);
while(th--){
scanf("%d%d",&a,&b);
for(i=1;i<=a;i++){
for(j=1;j<=a;j++){
r[i][j]=0;r[j][i]=0;}}top=0;ne=-1;flag=0;
for(i=0;i<b;i++){
scanf("%d%d",&x,&y);
r[x][y]++,r[y][x]++;}
for(i=1;i<=a;i++){if(add(i)==0)continue;
if(sol(i)==1){q[top++]=i;ne++;dfs(i);}}
if(ne==0){
for(i=1;i<=a;i++){n[i]=0;}
for(i=1;i<=a;i++){
for(j=1;j<=a;j++){
n[i]=n[i]+r[i][j];}}
for(i=1;i<=a;i++){
if(n[i]%2==1)flag=1;}
if(flag==1)printf("NO\n");
else printf("YES\n");}
else printf("NO\n");}}

////131A///
#include <stdio.h>

#define MAXN 5

char maze[MAXN][MAXN];
int visited[MAXN][MAXN];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int T, sx, sy, ex, ey;
int flag;

void dfs(int x, int y) {
	if (x == ex && y == ey) {
		flag = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN && !visited[nx][ny] && maze[nx][ny] == '.') {
			visited[nx][ny] = 1;
			dfs(nx, ny);
			if (flag) return;
			visited[nx][ny] = 0;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for (int i = 0; i < MAXN; i++) {
			scanf("%s", maze[i]);
		}

		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				visited[i][j] = 0;
			}
		}

		flag = 0;
		visited[sx][sy] = 1;
		dfs(sx, sy);

		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}

//122B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char s[100];
int i,t=1,max=1,h[20]={0},mt=1;
scanf("%s",s);
for(i=0;i<strlen(s);i++){
if(s[i]=='(')t++;
else if(s[i]==')')t--;
if(s[i]!='('&&s[i]!=')'&&s[i]!=',')h[t-1]++;
if(t>max)max=t;}
for(i=0;i<max;i++){
if(h[i]>mt)mt=h[i];}
printf("%d %d",max,mt);}

//122F
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
	int priority, i;
	friend bool operator < (node a, node b)
	{
		if (a.priority != b.priority)//优先级，出现概率
			return a.priority > b.priority;
		return a.i > b.i;//次数
	}
}p, a, b;


int main()
{
	int t, n, i = 0, j = 0;
	scanf("%d", &t);
	while (t--)
	{
		priority_queue <node> q;
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &p.priority);

			p.i = 1;
			q.push(p);
		}

		double sum = 0;
		for (i = 0; i < n - 1; i++)
		{
			a = q.top(); q.pop();

			b = q.top(); q.pop();

			p.priority = a.priority + b.priority;
			p.i = a.i + b.i;

			q.push(p);
			sum += p.i;
		}
		printf("%.3f\n", (double)sum / n);
	}
	return 0;
}

//122E
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct Edge {
	int to;
	struct Edge* next;
} Edge;

Edge* NewEdge(int to) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->to = to;
	e->next = NULL;
	return e;
}

Edge* edges[MAXN];
int weights[MAXN];
int dp[MAXN];
int ans = -0x3f3f3f3f;

void addEdge(int u, int v) {
	Edge* e = NewEdge(v);
	e->next = edges[u];
	edges[u] = e;
}

void dfs(int node, int parent) {
	dp[node] = weights[node];
	for (Edge* e = edges[node]; e; e = e->next) {
		if (e->to != parent) {
			dfs(e->to, node);
			if (dp[e->to] > 0) {
				dp[node] += dp[e->to];
			}
		}
	}
	ans = max(ans, dp[node]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weights[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}


///122D//
#include <bits/stdc++.h>
using namespace std;

#define debug printf("#@$@%\n")
const int mac = 5e5 + 10;

char s[mac];
vector<int>g[mac];
int cnt = 0, dp[mac][3];
int dp2[mac][3];

int dfs_wedge(char* s, int fa)
{
	if (!s[0]) return 0;
	int nb = 1;
	cnt++;
	if (fa != -1) {
		g[cnt].push_back(fa);
		g[fa].push_back(cnt);
	}
	if (s[0] == '0') return nb;
	int u = cnt;
	nb += dfs_wedge(s + 1, u);
	if (s[0] == '2') nb += dfs_wedge(s + nb, u);
	return nb;
}

void dfs(int u, int fa)
{
	int v1 = 0, v2 = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		dp[u][1] += dp[v][0];
		dp2[u][1] += dp2[v][0];
		if (v1) v2 = v;
		else v1 = v;
	}
	dp[u][1]++; dp2[u][1]++;
	if (v2) {
		dp2[u][0] = min(dp2[v1][1] + dp2[v2][0], dp2[v1][0] + dp2[v2][1]);
		dp[u][0] = max(dp[v1][0] + dp[v2][0], max(dp[v1][0] + dp[v2][1], dp[v1][1] + dp[v2][0]));
	}
	else if (v1) dp[u][0] = max(dp[v1][0], dp[v1][1]), dp2[u][0] = min(dp2[v1][0], dp2[v1][1]);
}

int main(int argc, char const* argv[])
{
	scanf("%s", s + 1);
	if (s[1] == '0') { printf("%d %d\n", 1, 0); return 0; }
	dfs_wedge(s + 1, -1);
	int n = strlen(s + 1);
	dfs(1, -1);
	printf("%d %d\n", max(dp[1][0], dp[1][1]), min(dp2[1][0], dp2[1][1]));
	return 0;
}
///122C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct Node {
	char val;
	struct Node* left, * right;
} Node;

Node* newNode(char val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

int idx;
char str[MAXN];
Node* buildTree() {
	if (idx >= strlen(str) || str[idx] == ' ') {
		idx++;
		return NULL;
	}
	Node* node = newNode(str[idx++]);
	node->left = buildTree();
	node->right = buildTree();
	return node;
}

int dfs(Node* node, int* depth) {
	if (node == NULL) {
		*depth = 0;
		return 0;
	}

	int left_depth, right_depth;
	int left_diameter = dfs(node->left, &left_depth);
	int right_diameter = dfs(node->right, &right_depth);

	*depth = max(left_depth, right_depth) + 1;
	return max(left_depth + right_depth, max(left_diameter, right_diameter));
}

int main() {
	int T;
	scanf("%d", &T);
	getchar();  // consume newline

	while (T--) {
		fgets(str, MAXN, stdin);
		idx = 0;
		Node* root = buildTree();
		int depth;
		printf("%d\n", dfs(root, &depth)+1);
	}

	return 0;
}

///121E//
#include <stdio.h>

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	int arr[3000];
	for (int i = 0; i <= n; i++) arr[i] = 0; // Initialize all elements to zero

	arr[r] = 1;

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a]++;
		arr[b]++;
	}

	if (n % 2 == 0) {
		int i = 1;
		for (; i <= n; i++) {
			if (arr[i] != 3) {
				break;
			}
		}
		if (arr[i] != 2) {
			printf("no\n");
			return 0;
		}
		i++;
		for (; i <= n; i++) {
			if (arr[i] != 1) {
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n");
		return 0;
	}
	else {
		int i = 1;
		for (; i <= n; i++) {
			if (arr[i] != 3) {
				break;
			}
		}
		for (; i <= n; i++) {
			if (arr[i] != 1) {
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n");
		return 0;
	}
}

///121F///
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int* a = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), cmp);
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			a[i + 1] = a[i] + a[i + 1];
			sum += a[i + 1];
			int j = i + 1;
			while (j < n - 1 && a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				j++;
			}
		}
		printf("%d\n", sum);
		free(a);
	}
	return 0;
}


///121D
#include <stdio.h>

#define MAXN 1005

typedef struct node {
	char data;
	int left;
	int right;
} Node;

Node tree[MAXN];
char preOrder[MAXN], inOrder[MAXN], postOrder[MAXN];
int n, preIndex, inIndex, postIndex;

void PreOrder(int root) {
	if (root) {
		preOrder[preIndex++] = tree[root].data;
		PreOrder(tree[root].left);
		PreOrder(tree[root].right);
	}
}

void InOrder(int root) {
	if (root) {
		InOrder(tree[root].left);
		inOrder[inIndex++] = tree[root].data;
		InOrder(tree[root].right);
	}
}

void PostOrder(int root) {
	if (root) {
		PostOrder(tree[root].left);
		PostOrder(tree[root].right);
		postOrder[postIndex++] = tree[root].data;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			getchar();
			scanf("%c %d %d", &tree[i].data, &tree[i].left, &tree[i].right);
		}
		preIndex = inIndex = postIndex = 0;
		PreOrder(1);
		InOrder(1);
		PostOrder(1);
		preOrder[preIndex] = inOrder[inIndex] = postOrder[postIndex] = '\0';
		printf("Case %d:\n", t);
		printf("%s\n", preOrder);
		printf("%s\n", inOrder);
		printf("%s\n", postOrder);
	}
	return 0;
}

///121B//
#include <stdio.h>
#include<string.h>
main()
{
	int number;
	int length;
	int a[100];
	char s[1000];
	int i;
	int up;
	int sum;
	int max;
	scanf("%d", &number);
	while (number--)
	{
		up = max = 0;
		sum = 0;
		memset(a, 0, sizeof(a));
		scanf("%s", &s);
		length = strlen(s);
		for (i = 0; i < length; i++)
		{

			if (s[i] != '(' && s[i] != ')' && s[i] != ',')
			{
				a[up]++;

			}
			if (s[i] == '(')
			{
				up++;
				max++;
			}
			if (s[i] == ')')
				up--;


		}

		for (i = 0; i <= max; i++)
			sum += a[i] * i;

		printf("%d\n", sum);


	}

}

//121A//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data[1001];
	int size;
} MinHeap;

void min_heapify(MinHeap* heap, int i) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < heap->size && heap->data[left] < heap->data[smallest]) {
		smallest = left;
	}
	if (right < heap->size && heap->data[right] < heap->data[smallest]) {
		smallest = right;
	}

	if (smallest != i) {
		int temp = heap->data[i];
		heap->data[i] = heap->data[smallest];
		heap->data[smallest] = temp;
		min_heapify(heap, smallest);
	}
}

int extract_min(MinHeap* heap) {
	int min = heap->data[0];
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;
	min_heapify(heap, 0);
	return min;
}

void insert(MinHeap* heap, int value) {
	heap->data[heap->size] = value;
	int i = heap->size;
	int parent = (i - 1) / 2;
	heap->size++;

	while (i > 0 && heap->data[parent] > heap->data[i]) {
		int temp = heap->data[i];
		heap->data[i] = heap->data[parent];
		heap->data[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
}

int huffman_cost(int* weights, int n) {
	MinHeap heap;
	heap.size = 0;
	for (int i = 0; i < n; i++) {
		insert(&heap, weights[i]);
	}

	int cost = 0;
	while (heap.size > 1) {
		int min1 = extract_min(&heap);
		int min2 = extract_min(&heap);
		int sum = min1 + min2;
		cost += sum;
		insert(&heap, sum);
	}
	return cost;
}

int main() {
	int n;
	scanf("%d", &n);
	int weights[1000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &weights[i]);
	}
	int cost = huffman_cost(weights, n);
	printf("%d\n", cost);
	return 0;
}


//112F

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node* left, * right;
} Node;

Node* build_tree(char* preorder, char* inorder, int len) {
	if (len <= 0) {
		return NULL;
	}
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = preorder[0];
	int mid;
	for (mid = 0; mid < len; mid++) {
		if (inorder[mid] == preorder[0]) {
			break;
		}
	}
	root->left = build_tree(preorder + 1, inorder, mid);
	root->right = build_tree(preorder + mid + 1, inorder + mid + 1, len - mid - 1);
	return root;
}

void postorder_traversal(Node* node) {
	if (node == NULL) {
		return;
	}
	postorder_traversal(node->left);
	postorder_traversal(node->right);
	printf("%c", node->data);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		char preorder[101], inorder[101];
		scanf("%s%s", preorder, inorder);
		Node* root = build_tree(preorder, inorder, n);
		postorder_traversal(root);
		printf("\n");
	}
	return 0;
}

//112E/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left, * right;
} Node;

Node* create_node(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

Node* insert_node(Node* node, int data) {
	if (node == NULL) {
		return create_node(data);
	}
	if (data < node->data) {
		node->left = insert_node(node->left, data);
	}
	else if (data > node->data) {
		node->right = insert_node(node->right, data);
	}
	return node;
}

void search_node(Node* node, int data, int* count) {
	(*count)++;
	if (node == NULL) {
		printf("Not found\n");
		return;
	}
	if (data == node->data) {
		printf("%d\n", data);
		return;
	}
	else if (data < node->data) {
		printf("%d->", node->data);
		search_node(node->left, data, count);
	}
	else {
		printf("%d->", node->data);
		search_node(node->right, data, count);
	}
}

int main() {
	int t, data;
	scanf("%d", &t);
	while (t--) {
		Node* root = NULL;
		while (scanf("%d", &data) && data != -1) {
			root = insert_node(root, data);
		}
		scanf("%d", &data);
		int count = 0;
		search_node(root, data, &count);
		printf("%d\n", count);
	}
	return 0;
}
//112D//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* left, * right;
} Node;

Node* create_tree(char** preorder) {
	if (**preorder == '#') {
		(*preorder)++;
		return NULL;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = **preorder;
	(*preorder)++;
	new_node->left = create_tree(preorder);
	new_node->right = create_tree(preorder);
	return new_node;
}

void inorder_traversal(Node* node) {
	if (node == NULL) {
		return;
	}
	inorder_traversal(node->left);
	printf("%c", node->data);
	inorder_traversal(node->right);
}

int main() {
	char preorder[101];
	scanf("%s", preorder);
	char* p = preorder;
	Node* root = create_tree(&p);
	inorder_traversal(root);
	printf("\n");
	return 0;
}

// 112C//
#include <stdio.h>

#define MAXN 1001

int tree[MAXN][2];
int depth[MAXN];

int max2(int a, int b) {
	return a > b ? a : b;
}

int calculate_depth(int node) {
	if (node == 0) {
		return 0;
	}
	if (depth[node] != 0) {
		return depth[node];
	}
	int left = calculate_depth(tree[node][0]);
	int right = calculate_depth(tree[node][1]);
	depth[node] = max2(left, right) + 1;
	return depth[node];
}

int main() {
	int n, i, left, right;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &left, &right);
		tree[i][0] = left;
		tree[i][1] = right;
	}
	int tree_depth = calculate_depth(1);
	printf("%d %d\n", tree_depth, tree[n][0]);
	return 0;
}


////112B///
#include<stdio.h>
#include<string.h>
int main()
{
	int t, i, j, s, n;
	char a[30], b[30];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s", a, b);
		n = strlen(a);
		s = 1;
		for (i = 0; i < n;)
		{
			for (j = 0; j < n; j++)
				if (a[i] == b[j])break;
			while (1)
			{
				i++; j--;//i右j左
				if (i >= n || j < 0)break;//越界
				if (a[i] == b[j])
					s *= 2;
				else break;
			}
		}
		printf("%d\n", s);
	}
}



/////112A//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

void PreOrderTraversal(TreeNode* node) {
	if (node) {
		printf("%c", node->data);
		PreOrderTraversal(node->left);
		PreOrderTraversal(node->right);
	}
}

void PostOrderTraversal(TreeNode* node) {
	if (node) {
		PostOrderTraversal(node->left);
		PostOrderTraversal(node->right);
		printf("%c", node->data);
	}
}

TreeNode* BuildTree(int levelLen, char* levelOrder, int inLen, char* inOrder) {
	if (levelLen == 0 || inLen == 0) {
		return NULL;
	}

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = levelOrder[0];
	root->left = NULL;
	root->right = NULL;

	int rootIdx = strchr(inOrder, root->data) - inOrder;
	int leftLen = rootIdx;
	int rightLen = inLen - rootIdx - 1;

	char leftLevelOrder[1000], rightLevelOrder[1000];
	int leftIdx = 0, rightIdx = 0;

	for (int i = 1; i < levelLen; ++i) {
		if (strchr(inOrder, levelOrder[i]) - inOrder < rootIdx) {
			leftLevelOrder[leftIdx++] = levelOrder[i];
		}
		else {
			rightLevelOrder[rightIdx++] = levelOrder[i];
		}
	}

	root->left = BuildTree(leftIdx, leftLevelOrder, leftLen, inOrder);
	root->right = BuildTree(rightIdx, rightLevelOrder, rightLen, inOrder + rootIdx + 1);

	return root;
}

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		char levelOrder[27], inOrder[27];
		scanf("%s %s", levelOrder, inOrder);

		int len = strlen(levelOrder);
		TreeNode* root = BuildTree(len, levelOrder, len, inOrder);

		PreOrderTraversal(root);
		printf(" ");
		PostOrderTraversal(root);
		printf("\n");
	}

	return 0;
}


/////111D///
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct btnode
{
	int data;
	struct btnode* lchild, * rchild;
}Bitnode, * Bitree;
Bitnode* CreatBitree_level()//简历树
{
	Bitnode* Q[1000];
	int front = 1, rear = 0;
	int ch;
	Bitnode* root = NULL, * s;
	while ((scanf("%d", &ch)), ch != -1)
	{
		if (ch == 0)
			s = NULL;
		else
		{
			s = (Bitnode*)malloc(sizeof(Bitnode));
			s->data = ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		Q[++rear] = s;
		if (rear == 1)
			root = s;
		else
		{
			if (s && Q[front])
				if (rear % 2 == 0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;
			if (rear % 2 == 1)
				front++;
		}

	}return root;
}

int depth(Bitnode* t)
{
	int high, lhigh, rhigh;
	if (!t)
		high = 0;
	else
	{
		lhigh = depth(t->lchild);
		rhigh = depth(t->rchild);
		if (lhigh > rhigh)
		{
			high = lhigh + 1;
		}
		else
			high = rhigh + 1;
	}
	return high;
}
void preorder(Bitnode* t)
{
	if (t)
	{

		preorder(t->lchild);
		preorder(t->rchild);
		printf(" %d", t->data);
	}
}
int main()
{
	int n, high;
	Bitnode* t;
	scanf("%d", &n);
	while (n--)
	{
		t = CreatBitree_level();
		high = depth(t);
		printf("%d", high);
		preorder(t);
		printf("\n");
	}
	return 0;
}

///////////111F////
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.14159265

int BiTree[10000];

void InTraverse(int T[], int e)  //递归中序遍历二叉树T中序号为e的子树
{
	if (T[2 * e + 1] != 0) InTraverse(T, 2 * e + 1);  //序号为e的节点的左子树不空
	printf(" %d", T[e]);    //访问树T中序号为e的节点
	if (T[2 * e + 2] != 0) InTraverse(T, 2 * e + 2);  //序号为e的节点的右子树不空
}

void InOrderTraverse(int T[])
{
	InTraverse(T, 0);   //递归中序遍历树T中序号为0的树
	printf("\n");
}

int TreeDeep(int T[], int n)
{
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		if (T[i] != 0)  break;
	}
	return (int)(log(i + 1) / log(2) + 1.1);
}

int main()
{
	int n, t, i;
	scanf("%d", &n);
	while (n--)
	{
		i = 0;
		while (scanf("%d", &t) && t != -1)
		{
			BiTree[i++] = t;
		}
		printf("%d", TreeDeep(BiTree, i));
		InOrderTraverse(BiTree);
	}
	return 0;
}

///////////111A/////
#include <stdio.h>
#include <string.h>
 #include <ctype.h>
#include <math.h>

 int BiTree[10000];

 void PreTraverse(int T[], int e)  //递归先序遍历二叉树T中序号为e的子树
 {
	printf(" %d", T[e]);    //访问树T中序号为e的节点
   if (T[2 * e + 1] != 0) PreTraverse(T, 2 * e + 1);  //序号为e的节点的左子树不空
   if (T[2 * e + 2] != 0) PreTraverse(T, 2 * e + 2);  //序号为e的节点的右子树不空
 }

 void PreOrderTraverse(int T[])
 {
		 PreTraverse(T, 0);   //递归先序遍历树T中序号为0的树
		 printf("\n");
	}

 int TreeDeep(int T[], int n)
{
		 int i;
		 for (i = n - 1; i >= 0; i--)
			 {
				if (T[i] != 0)  break;
		 }
		return (int)(log(i + 1) / log(2) + 1.1);
	 }

int main()
 {
		int n, t, i;
		 scanf("%d", &n);
	while (n--)
			{
			  i = 0;
				 while (scanf("%d", &t) && t != -1)
					 {
						   BiTree[i++] = t;
					 }
				 printf("%d", TreeDeep(BiTree, i));
				 PreOrderTraverse(BiTree);
			 }
		 return 0;
	}
///112E//

#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode {
	char data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
} ThreadNode, * ThreadTree;

int index = 0;  // 全局索引变量来读取输入字符串
ThreadNode* pre = NULL;  // 全局变量，始终指向刚刚访问过的结点

// 创建二叉树
ThreadNode* create(char* str) {
	ThreadNode* node;
	if (str[index] == '#' || str[index] == '\0') {
		return NULL;
	}
	else {
		node = (ThreadNode*)malloc(sizeof(ThreadNode));
		node->data = str[index];
		node->ltag = node->rtag = 0;

		++index;
		node->lchild = create(str);
		++index;
		node->rchild = create(str);
	}
	return node;
}

// 中序线索化
void in_threading(ThreadTree p) {
	if (p) {
		in_threading(p->lchild);  // 递归左孩子线索化

		if (!p->lchild) {  // 如果该结点没有左孩子，设置ltag为1，并把lchild指向前驱
			p->ltag = 1;
			p->lchild = pre;
		}

		if (pre && !pre->rchild) {  // 如果前驱没有右孩子，设置rtag为1，并把rchild指向后继（当前结点p）
			pre->rtag = 1;
			pre->rchild = p;
		}

		pre = p;  // 保持pre指向刚访问过的结点
		in_threading(p->rchild);  // 递归右孩子线索化
	}
}

// 中序遍历线索二叉树
void in_order(ThreadTree p) {
	while (p) {
		while (p->ltag == 0) {
			p = p->lchild;
		}
		printf("%c", p->data);

		while (p->rtag == 1 && p->rchild != NULL) {
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		char str[50];
		scanf("%s", str);

		index = 0;
		pre = NULL;

		ThreadTree root = create(str);
		in_threading(root);
		in_order(root);

		printf("\n");
	}

	return 0;
}



////111C///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
} Node;

Node* create_node(char data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* build_tree(char* preorder, char* inorder, int pre_start, int pre_end, int in_start, int in_end) {
	if (pre_start > pre_end || in_start > in_end) {
		return NULL;
	}

	Node* node = create_node(preorder[pre_start]);
	int in_pos = -1;
	for (int i = in_start; i <= in_end; i++) {
		if (inorder[i] == preorder[pre_start]) {
			in_pos = i;
			break;
		}
	}

	int left_length = in_pos - in_start;

	node->left = build_tree(preorder, inorder, pre_start + 1, pre_start + left_length, in_start, in_pos - 1);
	node->right = build_tree(preorder, inorder, pre_start + left_length + 1, pre_end, in_pos + 1, in_end);

	return node;
}

void postorder_traversal(Node* root) {
	if (root == NULL) {
		return;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%c", root->data);
}

void free_tree(Node* root) {
	if (root == NULL) {
		return;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main() {
	char preorder[30], inorder[30];
	while (scanf("%s %s", preorder, inorder) != EOF) {
		int pre_length = strlen(preorder);
		int in_length = strlen(inorder);
		Node* root = build_tree(preorder, inorder, 0, pre_length - 1, 0, in_length - 1);
		postorder_traversal(root);
		printf("\n");
		free_tree(root);
	}
	return 0;
}

/////////111B//2604
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
} Node;

int index_preorder = 0;

Node* create_node(char data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* build_tree(char* preorder) {
	if (preorder[index_preorder] == '#' || index_preorder >= strlen(preorder)) {
		index_preorder++;
		return NULL;
	}
	Node* node = create_node(preorder[index_preorder++]);
	node->left = build_tree(preorder);
	node->right = build_tree(preorder);
	return node;
}

void inorder_traversal(Node* root) {
	if (root == NULL) {
		return;
	}
	inorder_traversal(root->left);
	printf("%c", root->data);
	inorder_traversal(root->right);
}

void postorder_traversal(Node* root) {
	if (root == NULL) {
		return;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%c", root->data);
}

void level_traversal(Node* root) {
	if (root == NULL) {
		return;
	}
	int front = -1, rear = -1, last = 0;
	Node* queue[2000];
	queue[++rear] = root;
	while (front != rear) {
		Node* node = queue[++front];
		printf("%c", node->data);
		if (node->left != NULL) {
			queue[++rear] = node->left;
		}
		if (node->right != NULL) {
			queue[++rear] = node->right;
		}
	}
}

void free_tree(Node* root) {
	if (root == NULL) {
		return;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main() {
	char preorder[2000];
	while (scanf("%s", preorder) != EOF) {
		index_preorder = 0;
		Node* root = build_tree(preorder);
		inorder_traversal(root);
		printf(" ");
		postorder_traversal(root);
		printf(" ");
		level_traversal(root);
		printf("\n");
		free_tree(root);
	}
	return 0;
}

////101B/////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	int level;
	struct Node* next;
} Node;

Node* create_node(char data, int level) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->level = level;
	new_node->next = NULL;
	return new_node;
}

void parse_generalized_list(char* str, Node** head, int level) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			level++;
		}
		else if (str[i] == ')') {
			level--;
		}
		else if (str[i] != ',') {
			Node* new_node = create_node(str[i], level);
			if (*head == NULL) {
				*head = new_node;
			}
			else {
				Node* temp = *head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new_node;
			}
		}
	}
}

void print_level_x(Node* head, int level) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->level == level) {
			printf("%c\n", temp->data);
		}
		temp = temp->next;
	}
}

int main() {
	char input_str[256];
	int target_level;
	Node* head = NULL;

	scanf("%s", input_str);

	scanf("%d", &target_level);

	parse_generalized_list(input_str, &head, 0);
	print_level_x(head, target_level);

	return 0;
}


//////101A////
#include <stdio.h>
#include <string.h>

int max1(int a, int b) {
	return a > b ? a : b;
}

int getDepth(const char* input, int* index) {
	int depth = 0;
	while (input[*index] != '\0') {
		if (input[*index] == '(') {
			(*index)++;
			depth = max1(depth, getDepth(input, index) + 1);
		}
		else if (input[*index] == ')') {
			(*index)++;
			return depth;
		}
		else {
			(*index)++;
		}
	}
	return depth;
}

int main() {
	char input[100];
	scanf("%s", input);
	int index = 0;
	int depth = getDepth(input, &index);
	printf("%d\n", depth);
	return 0;
}

//////92G
#include <stdio.h>

int ackerman(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	else if (n == 0) {
		return ackerman(m - 1, 1);
	}
	else {
		return ackerman(m - 1, ackerman(m, n - 1));
	}
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	int result = ackerman(m, n);
	printf("%d\n", result);

	return 0;
}


////92F/////
#include <stdio.h>
#include <string.h>

int isValidBrackets(const char* str) {
	char stack[101];
	int top = -1;

	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			stack[++top] = str[i];
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (top < 0) return 0;
			if (str[i] == ')' && stack[top] != '(') return 0;
			if (str[i] == ']' && stack[top] != '[') return 0;
			if (str[i] == '}' && stack[top] != '{') return 0;
			--top;
		}
	}

	return top == -1;
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();

	for (int i = 0; i < t; ++i) {
		char expression[101];
		fgets(expression, sizeof(expression), stdin);
		expression[strcspn(expression, "\n")] = '\0';

		if (isValidBrackets(expression)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}

///////92E////
#include <stdio.h>

int isUglyNumber(int num) {
	if (num <= 0) return 0;

	while (num % 2 == 0) {
		num /= 2;
	}
	while (num % 3 == 0) {
		num /= 3;
	}
	while (num % 5 == 0) {
		num /= 5;
	}

	return num == 1;
}

int main() {
	int n;
	scanf("%d", &n);

	if (isUglyNumber(n)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}
///////////////92D////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
int a[10], b[10];

int fun() {
	int i, x = 0, y = 0;
	for (i = 0; i < 10; i++) {
		x = x + b[i]; y = y + a[i] * b[i];
	}
	if (x == 10 && y == 10)return 1;
	else return 0;
}

int main() {
	int i, j = 0, k;
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	while (fun() != 1) {
		k = 0;
		for (i = 0; i < 10; i++) {
			if (b[i] == a[j])k++;
		}
		b[j] = k; j++; j = j % 10;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
}
////////92C//////////
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains_char(const char* str, char c) {
	while (*str) {
		if (*str == c) {
			return true;
		}
		str++;
	}
	return false;
}

void remove_chars(char* str1, const char* str2) {
	char* dst = str1;
	while (*str1) {
		if (!contains_char(str2, *str1)) {
			*dst = *str1;
			dst++;
		}
		str1++;
	}
	*dst = '\0';
}

int main() {
	char str1[1000];
	char str2[1000];

	fgets(str1, sizeof(str1), stdin);
	if (str1[strlen(str1) - 1] == '\n') {
		str1[strlen(str1) - 1] = '\0';
	}

	fgets(str2, sizeof(str2), stdin);
	if (str2[strlen(str2) - 1] == '\n') {
		str2[strlen(str2) - 1] = '\0';
	}

	remove_chars(str1, str2);

	printf("%s\n", str1);

	return 0;
}

///////////92B///
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int compare(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	if (arg1 % 2 == 0 && arg2 % 2 == 0) {
		return arg1 - arg2;
	}
	else if (arg1 % 2 != 0 && arg2 % 2 != 0) {
		return arg2 - arg1;
	}
	else {
		return (arg1 % 2 == 0) ? 1 : -1;
	}
}

int main() {
	int arr[1000];
	int n = 0;

	while (scanf("%d", &arr[n]) == 1) {
		n++;
	}

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n-1; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n-1]);

	return 0;
}

/////92A////////
#include <stdio.h>

int count_combinations = 0;

void find_combinations(int n, int start, int sum, int* temp, int index) {
	int i = 0;
	if (sum == n) {
		count_combinations++;
		for (i = 0; i < index-1; i++) {
			printf("%d ", temp[i]);
		}
		printf("%d\n", temp[i]);
		if (count_combinations != 1) {}
		printf("\n");


		return;
	}

	for (int i = start; i >= 1; i--) {
		if (sum + i > n) {
			continue;
		}
		temp[index] = i;
		find_combinations(n, i - 1, sum + i, temp, index + 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int temp[10000];
	find_combinations(n, n, 0, temp, 0);

	return 0;
}


///91F////
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool containsOne(int n) {
	char str[12];
	sprintf(str, "%d", n);
	return strchr(str, '1') != NULL;
}

int countOnes(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		char str[12];
		sprintf(str, "%d", i);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == '1') {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d\n", countOnes(n));

	for (int i = n; i > 0; i--) {
		if (containsOne(i)) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int lastRemaining(int n, int m) {
	if (n < 1 || m < 1) {
		return -1;
	}

	int last = 0;
	for (int i = 2; i <= n; i++) {
		last = (last + m) % i;
	}
	return last + 1;
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	int lastNumber = lastRemaining(n, m);

	printf("%d\n", lastNumber);

	return 0;
}


///91D//
#include <stdio.h>
#include <string.h>

char firstNotRepeatingChar(char* str) {
	int len = strlen(str);
	int count[256] = { 0 };

	for (int i = 0; i < len; i++) {
		count[str[i]]++;
	}

	for (int i = 0; i < len; i++) {
		if (count[str[i]] == 1) {
			return str[i];
		}
	}

	return '\0';
}

int main() {
	char input[1000];

	scanf("%s", input);

	char firstUniqueChar = firstNotRepeatingChar(input);
	if (firstUniqueChar != '\0') {
		printf("%c\n", firstUniqueChar);
	}
	else {
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseWords(char* str) {
	int len = strlen(str);
	char* temp = (char*)malloc(sizeof(char) * (len + 1));
	int i = len - 1;
	int j = 0;

	while (i >= 0) {
		while (i >= 0 && str[i] != ' ') {
			i--;
		}
		int start = i + 1;
		while (str[start] != ' ' && str[start] != '\0') {
			temp[j++] = str[start++];
		}
		if (i >= 0) {
			temp[j++] = ' ';
		}
		i--;
	}
	temp[j] = '\0';

	strcpy(str, temp);
	free(temp);
}

int main() {
	char input[1000];


	while (scanf(" \"%[^\"]\"", input)!=EOF) {	
		reverseWords(input);
		printf("\"%s\"\n", input);
	}

	return 0;
}

///91B////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_two_numbers(int arr[], int n, int target) {
	int left = 0;
	int right = n - 1;

	while (left < right) {
		int current_sum = arr[left] + arr[right];
		if (current_sum == target) {
			printf("%d %d\n", arr[left], arr[right]);
			return;
		} else if (current_sum < target) {
			left++;
		} else {
			right--;
		}
	}

	printf("No such pair found\n");
}

int main() {
	char input[1000];
	int arr[500], n = 0, target;

	fgets(input, sizeof(input), stdin);
	char *token = strtok(input, " ");
	while (token != NULL) {
		arr[n++] = atoi(token);
		token = strtok(NULL, " ");
	}

	scanf("%d", &target);

	find_two_numbers(arr, n, target);

	return 0;
}


///91A////
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int numbers[1000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}

	qsort(numbers, n, sizeof(int), compare);

	for (int i = 0; i < k; i++) {
		printf("%d", numbers[i]);
		if (i < k - 1) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}



//82F//

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
	int row;
	int col;
	int value;
} Triple;

int find_position(Triple matrix[], int n, int row, int col) {
	for (int i = 0; i < n; i++) {
		if (matrix[i].row == row && matrix[i].col == col) {
			return i;
		}
	}
	return -1;
}

int main() {
	Triple matrixA[MAX_SIZE], matrixB[MAX_SIZE], result[MAX_SIZE];
	int row, col, value;
	int indexA = 0, indexB = 0, indexResult = 0;

	while (true) {
		scanf("%d,%d,%d", &row, &col, &value);
		if (row == -1 && col == -1 && value == -1) {
			break;
		}
		matrixA[indexA].row = row;
		matrixA[indexA].col = col;
		matrixA[indexA].value = value;
		indexA++;
	}

	while (true) {
		scanf("%d,%d,%d", &row, &col, &value);
		if (row == -1 && col == -1 && value == -1) {
			break;
		}
		matrixB[indexB].row = row;
		matrixB[indexB].col = col;
		matrixB[indexB].value = value;
		indexB++;
	}

	for (int i = 0; i < indexA; i++) {
		for (int j = 0; j < indexB; j++) {
			if (matrixA[i].col == matrixB[j].row) {
				int newRow = matrixA[i].row;
				int newCol = matrixB[j].col;
				int newValue = matrixA[i].value * matrixB[j].value;

				int position = find_position(result, indexResult, newRow, newCol);
				if (position != -1) {
					result[position].value += newValue;
				}
				else {
					result[indexResult].row = newRow;
					result[indexResult].col = newCol;
					result[indexResult].value = newValue;
					indexResult++;
				}
			}
		}
	}

	if (indexResult == 0) {
		printf("No non-zero number exists!\n");
	}
	else {
		for (int i = 0; i < indexResult; i++) {
			printf("%d,%d,%d\n", result[i].row, result[i].col, result[i].value);
		}
	}

	return 0;
}


///82E///
#include <stdio.h>

int max_subarray_sum(int arr[], int n) {
	int max_sum = arr[0];
	int current_sum = arr[0];

	for (int i = 1; i < n; i++) {
		current_sum = (current_sum > 0) ? (current_sum + arr[i]) : arr[i];
		max_sum = (current_sum > max_sum) ? current_sum : max_sum;
	}

	return max_sum;
}

int main() {
	int n,i=0;
	int arr[10000];

	while(scanf("%d", &arr[i])!=EOF) {
		i++;
	}
	n = i;


	int max_sum = max_subarray_sum(arr, n);
	printf("%d\n", max_sum);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义栈结构体
typedef struct Stack {
	int data[MAX_SIZE];
	int top;
} Stack;

// 初始化栈
void init(Stack *s) {
	s->top = -1;
}

// 判断栈是否为空
int is_empty(Stack *s) {
	return s->top == -1;
}

// 判断栈是否已满
int is_full(Stack *s) {
	return s->top == MAX_SIZE - 1;
}

// 入栈
void push(Stack *s, int x) {
	if (is_full(s)) {
		printf("Stack overflow.\n");
		exit(1);
	}
	s->data[++(s->top)] = x;
}

// 出栈
int pop(Stack *s) {
	if (is_empty(s)) {
		printf("Stack underflow.\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

// 颠倒栈
void reverse(Stack *s) {
	int x;
	if (!is_empty(s)) {
		x = pop(s);
		reverse(s);
		push(s, x);
	}
}

int main() {
	Stack s;
	int x;

	init(&s);

	// 读入数据并入栈
	while (scanf("%d", &x) != EOF) {
		push(&s, x);
	}

	// 颠倒栈
	reverse(&s);

	// 输出结果
	while (!is_empty(&s)) {
		printf("%d ", pop(&s));
	}
	printf("\n");

	return 0;
}


#include <stdio.h>

int gcd(int m, int n) {
	while (n != 0) {
		int remainder = m % n;
		m = n;
		n = remainder;
	}
	return m;
}

int lcm(int m, int n) {
	return m * n / gcd(m, n);
}

int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		printf("%d\n", lcm(m, n));
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void generate_combinations(int* elements, int n, int k, int start, int* combination, int index) {
	int i;
	if (index == k) {
		for (i = 0; i < k-1; i++) {
			printf("%d ", combination[i]);
		}
		printf("%d\n", combination[i]);
		return;
	}

	for (int i = start; i < n; i++) {
		combination[index] = elements[i];
		generate_combinations(elements, n, k, i + 1, combination, index + 1);
	}
}

int main() {
	int k, n,tmp;
	scanf("k=%d", &k);
	n = 0;
	while (scanf("%d", &tmp) != EOF) { n++; }


	int* elements = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		elements[i] = i + 1;
	}

	int* combination = (int*)malloc(k * sizeof(int));
	generate_combinations(elements, n, k, 0, combination, 0);

	free(elements);
	free(combination);

	return 0;
}

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int max2(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, T;
	scanf("%d %d", &n, &T);
	int* weights = (int*)malloc((n + 1) * sizeof(int));
	int* values = (int*)malloc((n + 1) * sizeof(int));

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &weights[i], &values[i]);
	}

	int** dp = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int*)malloc((T + 1) * sizeof(int));
	}

	// 初始化动态规划数组
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= T; j++) {
		dp[0][j] = 0;
	}

	// 动态规划
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= T; j++) {
			if (j < weights[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max2(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
			}
		}
	}

	printf("%d\n", dp[n][T]);

	// 释放内存
	for (int i = 0; i <= n; i++) {
		free(dp[i]);
	}
	free(dp);
	free(weights);
	free(values);

	return 0;
}



#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int* arr, int start, int end) {
	int i;
	if (start == end) {
		for (i = 0; i < end; i++) {
			printf("%d ", arr[i]);
		}
		printf("%d\n", arr[i]);
		return;
	}

	for (int i = start; i <= end; i++) {
		swap(&arr[start], &arr[i]);
		permute(arr, start + 1, end);
		swap(&arr[start], &arr[i]); // 回溯，恢复原来的数组顺序
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[1000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	permute(arr, 0, n - 1);

	return 0;
}



#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char* str) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	char input[100];

	scanf("%[^@]", input);

	bool result = is_palindrome(input);

	if (result) {
		printf("是回文\n");
	}
	else {
		printf("不是回文\n");
	}

	return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_reverse(const char* sequence1, const char* sequence2) {
	int len1 = strlen(sequence1);
	int len2 = strlen(sequence2);

	if (len1 != len2) {
		return false;
	}

	for (int i = 0; i < len1; i++) {
		if (sequence1[i] != sequence2[len1 - i - 1]) {
			return false;
		}
	}

	return true;
}

bool check_pattern(const char* input) {
	const char* ampersand = strchr(input, '&');
	if (ampersand == NULL) {
		return false;
	}

	int seq1_len = ampersand - input;
	int seq2_len = strlen(input) - seq1_len - 1;

	char sequence1[seq1_len + 1];
	strncpy(sequence1, input, seq1_len);
	sequence1[seq1_len] = '\0';

	char sequence2[seq2_len + 1];
	strcpy(sequence2, ampersand + 1);

	return is_reverse(sequence1, sequence2);
}

int main() {
	char input[100];

	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0; // remove trailing newline

	bool result = check_pattern(input);

	if (result) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}

////c////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* p;

double parse_expression();

double parse_number() {
	double num = 0;
	while (isdigit(*p)) {
		num = num * 10 + *p - '0';
		p++;
	}
	return num;
}

double parse_parenthesis() {
	if (*p == '('|| *p == '[') {
		p++;
		double result = parse_expression();
		if (*p == ')'|| *p == ']') {
			p++;
			return result;
		}
	}
	return parse_number();
}

double parse_term() {
	double left = parse_parenthesis();
	while (*p == '*' || *p == '/'|| *p == 'x') {
		char op = *p++;
		double right = parse_parenthesis();
		if (op == '*' || op == 'x') {
			left *= right;
		}
		else {
			left /= right;
		}
	}
	return left;
}

double parse_expression() {
	double left = parse_term();
	while (*p == '+' || *p == '-') {
		char op = *p++;
		double right = parse_term();
		if (op == '+') {
			left += right;
		}
		else {
			left -= right;
		}
	}
	return left;
}

int main() {
	char expression[101];
	while (fgets(expression, sizeof(expression), stdin)) {
		p = expression;
		double result = parse_expression();
		printf("%.0f\n", result);
	}
	return 0;
}


////81E//
#include<stdio.h>
#include<string.h>

typedef struct
{
	int data[100];
	int top;
}SqStack;

SqStack S;
int N;
int Original[100];
int Prestack[100];
long long count;

void Put(int i, int j){
	int k;
	if (i == N){
		count++;
		for (i = S.top; i >= 0; i--){
			Prestack[j++] = S.data[i];
		}
		for (i = 0; i < N - 1; i++){
			printf("%d ", Prestack[i]);
		}
		printf("%d\n", Prestack[i]);
		return;
	}

	for (k = 1; k <= 2; k++){
		switch (k){
		case 1:
			if (S.top >= 0){
				Prestack[j] = S.data[S.top];
				S.top--; 
				Put(i, j + 1);
				S.top++;
				S.data[S.top] = Prestack[j];
			}
			break;
		case 2:
			S.top++;
			S.data[S.top] = Original[i];
			Put(i + 1, j);
			S.top--;
			break;
		}
	}
}
int main()
{
	int i;
	while (~scanf("%d", &N)){
		S.top = -1; count = 0;
		for (i = 0; i < N; i++){
			scanf("%d", &Original[i]);
		}
		Put(0, 0);
	}
}





////lisp//2033
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR_LEN 1000

int compute(char* expr, int* pos) {
	while (expr[*pos] == ' ') {
		(*pos)++;
	}

	if (expr[*pos] == '(') {
		(*pos)++;
		char op = expr[*pos];
		(*pos) += 2;

		int res = (op == '+' || op == '*') ? (op == '+' ? 0 : 1) : compute(expr, pos);

		while (expr[*pos] != ')') {
			if (op == '+') {
				res += compute(expr, pos);
			}
			else if (op == '-') {
				res -= compute(expr, pos);
			}
			else if (op == '*') {
				res *= compute(expr, pos);
			}
			else if (op == '/') {
				res /= compute(expr, pos);
			}
		}
		(*pos)++;

		return res;
	}
	else {
		int num = 0;
		while (expr[*pos] >= '0' && expr[*pos] <= '9') {
			num = num * 10 + (expr[*pos] - '0');
			(*pos)++;
		}

		return num;
	}
}

int main() {
	char expr[MAX_EXPR_LEN];
	fgets(expr, MAX_EXPR_LEN, stdin);
	int pos = 0;

	printf("%d\n", compute(expr, &pos));
	return 0;
}



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int top;
} Stack;

void init_stack(Stack* stack) {
	stack->top = -1;
}

int is_empty(Stack* stack) {
	return stack->top == -1;
}

void push(Stack* stack, int value) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack overflow.\n");
		return;
	}
	stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
	if (is_empty(stack)) {
		printf("Stack underflow.\n");
		return -1;
	}
	return stack->data[stack->top--];
}

int main() {
	int decimal_number;
	Stack stack;
	init_stack(&stack);

	scanf("%d", &decimal_number);

	while (decimal_number != 0) {
		push(&stack, decimal_number % 8);
		decimal_number /= 8;
	}

	while (!is_empty(&stack)) {
		printf("%d", pop(&stack));
	}
	printf("\n");

	return 0;
}

#include <stdio.h>
#include <string.h>

void reverse(char* start, char* end) {
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main() {
	char input[101];
	while (gets(input) != NULL) {
		int length = strlen(input);

		if (length % 2 == 0) {
			reverse(input, input + length / 2 - 1);
			reverse(input + length / 2, input + length - 1);
		}
		else {
			reverse(input, input + (length - 1) / 2 - 1);
			reverse(input + (length + 1) / 2, input + length - 1);
		}

		printf("%s\n", input);
	}

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

Node* insertNode(Node* head, int data) {
	if (head == NULL) {
		return createNode(data);
	}
	Node* currentNode = head;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	Node* newNode = createNode(data);
	newNode->prev = currentNode;
	currentNode->next = newNode;
	return head;
}

void reversePrint(Node* head, int a, int b) {
	Node* currentNode = head;
	int index = 1;
	while (currentNode != NULL && index < a) {
		currentNode = currentNode->next;
		index++;
	}
	while (currentNode != NULL && index < b) {
		currentNode = currentNode->next;
		index++;
	}
	while (currentNode->prev != NULL && index > a) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->prev;
		index--;
	}
	printf("%d\n", currentNode->data);
}

int main() {
	int n, a, b, num;
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d %d", &a, &b);
		Node* head = NULL;
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			head = insertNode(head, num);
		}
		reversePrint(head, a, b);
		scanf("%d", &n);
	}
	return 0;
}


#define swap(a,b) {int t; t=a; a=b; b=t; }
//////////////////////////
int main() {
	int n, i, j;
	int a[120];
	int min=0, minl=0;
	scanf("%d", &n);
	for (i = 0; i < n * n; i++) {
		scanf("%d", &a[i]);
		if (a[i] < a[min]) {
			minl = min;
			min = i;
		}
		else if (a[i] < a[minl]) {
			minl = i;
		}
	}
	swap(a[0], a[min]);
	swap(a[n * n - 1], a[minl]);

	for (i = 0; i < n * n; i++) {
		if(i%n==n-1) {
			printf("%d\n", a[i]);
		}
		else {
			printf("%d ", a[i]);
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
// 定义单链表结构体
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// 创建新结点
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// 向链表中插入元素
Node* insertNode(Node* head, int x) {
	Node* newNode = createNode(x);
	if (head == NULL || head->data > x) {
		newNode->next = head;
		return newNode;
	}
	Node* current = head;
	while (current->next != NULL && current->next->data < x) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
	return head;
}

// 打印链表
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// 释放链表
void freeList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}

int main() {
	int n, x, data;
	Node* head = NULL;

	// 输入链表长度和数据
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		head = insertNode(head, data);
	}

	// 输入插入数据
	scanf("%d", &x);
	head = insertNode(head, x);

	// 输出链表
	printList(head);

	// 释放链表
	freeList(head);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char input[1000];
	fgets(input, 1000, stdin);

	int len = strlen(input);
	int i = 0;
	while (i < len) {
		if (isdigit(input[i])) {
			long long num = 0;
			while (isdigit(input[i])) {
				num = num * 10 + (input[i] - '0');
				i++;
			}
			printf("%lld    ", num);
		} else {
			i++;
		}
	}

	return 0;
}

typedef struct list_node {
	int data;
	struct list_node* next;
}L;
L* create_node(int data) {
	L* p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	p->data = data;
	p->next = NULL;
	return p;
}
void tail_insert(L* pH, L* new) {
	L* p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void top_insert(L* pH, L* new) {
	L* p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}

void rev_node(L* pH, int k)//swap
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL) {
		if (p == pH) {
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else {
			back = pH;
			while (back->next != p) {
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void sort_list(L* header) {
	int sorted = 1;
	int count = 0;
	L* node = header->next;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	while (sorted) {
		sorted = 0;
		for (int i = 0; i < count - 1; i++) {
			node = header->next;
			for (int j = 0; j < i; j++) {
				node = node->next;
			}
			if (node->data > node->next->data) {
				rev_node(header, i + 1);
				sorted = 1;
			}
		}
	}
}

int main() {
	int n, i, tmp, k, maxr;
	L* header1 = create_node(0);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header1, create_node(tmp));
	}

	//print_node(header);
	return 0;
}


///////////////////////////
typedef struct list_node {
	char name[30];
	float data[3];
	struct list_node* next;
}L;
L* create_node(char *name, float data1,  float data2, float data3) {
	L* p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	strcpy(p->name , name);
	p->data[0] = data1;
	p->data[1] = data2;
	p->data[2] = data3;
	p->next = NULL;
	return p;
}
void tail_insert(L* pH, L* new) {
	L* p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void top_insert(L* pH, L* new) {
	L* p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}

void print_score(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p) {
		if (p->data[0] + p->data[1] + p->data[2] >= 180) {
			printf("%s -- pass exam\n", p->name);
		}
		p = p->next;
	}
	p = pH;
	p = p->next;
	while (NULL != p) {
		if (p->data[0] + p->data[1] + p->data[2] <= 180) {
			printf("%s -- not pass exam\n", p->name);
		}
		p = p->next;
	}
	p = pH;
	p = p->next;
	while (NULL != p) {
		if (p->data[0] + p->data[1] + p->data[2] ==300) {
			printf("%s -- 3 x 100.0\n", p->name);
		}
		p = p->next;
	}
}

int main() {
	int n, i,  k, maxr;
	float tmp, tmp1, tmp2, tmp3;
	char tmpn[30];
	L* header1 = create_node("0",0,0,0);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", &tmpn);
		scanf("%f", &tmp1);
		scanf("%f", &tmp2);
		scanf("%f", &tmp3);
		tail_insert(header1, create_node(tmpn,tmp1,tmp2,tmp3));
	}

	//travel_list(header1);
	//sort1(header1, min_node(header1));
	//travel_list(header1);

	print_score(header1);
	//print_node(header);
	return 0;
}

typedef struct list_node {
	int data;
	struct list_node* next;
}L;
L* create_node(int data) {
	L* p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	p->data = data;
	p->next = NULL;
	return p;
}
void tail_insert(L* pH, L* new) {
	L* p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void top_insert(L* pH, L* new) {
	L* p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
void print_node1(L* pH) {
	L* p = pH;
	p = p->next;
	int cnt = 1;
	while (NULL != p) {
		if (cnt % 2) {
			printf("%d ", p->data);
		}
		cnt++;
		p = p->next;
	}
	printf(" \n");
}
void print_node2(L* pH) {
	L* p = pH;
	p = p->next;
	int cnt = 1;
	while (NULL != p) {
		if (cnt % 2==0) {
			printf("%d ", p->data);
		}
		cnt++;
		p = p->next;
	}
}
void rev_node(L* pH, int k)//swap
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL) {
		if (p == pH) {
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else {
			back = pH;
			while (back->next != p) {
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void sort_list(L* header) {
	int sorted = 1;
	int count = 0;
	L* node = header->next;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	while (sorted) {
		sorted = 0;
		for (int i = 0; i < count - 1; i++) {
			node = header->next;
			for (int j = 0; j < i; j++) {
				node = node->next;
			}
			if (node->data > node->next->data) {
				rev_node(header, i + 1);
				sorted = 1;
			}
		}
	}
}
void sort1(L* header, int min) {
	L* ph = header;
	L* p = header;
	L* p2 = p->next;
	L* prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == min) {
			prev->next = p->next;
			p->next = p2;
			ph->next = p;
			return 0;
		}
	}
	//printf("Delete Failed\n");
	return -1;
}
void remove_duplicates(L* pH) {
	L* current = pH->next;
	L* runner = NULL;
	L* prev = NULL;

	while (current != NULL) {
		runner = current->next;
		prev = current;

		while (runner != NULL) {
			if (current->data == runner->data) {
				L* temp = runner;
				prev->next = runner->next;
				runner = runner->next;
				free(temp);
			}
			else {
				prev = runner;
				runner = runner->next;
			}
		}
		current = current->next;
	}
}
int delete_list_node(L* pH, int data) {
	L* p = pH;
	L* prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == data) {
			if (p->next != NULL) {
				prev->next = p->next;
				free(p);
			}
			else {
				prev->next = NULL;
				free(p);
			}
			return 0;
		}
	}
	//printf("Delete Failed\n");
	return -1;
}

int min_node(L* pH) {
	L* p = pH;
	L* prev = NULL;
	int min = 32767;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data < min) {
			min = p->data;
		}
	}
	return min;
}
int minr_node(L* pH, int m, L* pH2) {
	L* p = pH;
	L* prev = NULL;
	int cnt = 0;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data < m) {
			tail_insert(pH2, create_node(p->data));
		}
		else if (p->data > m) {
			cnt++;
		}
	}
	return cnt;
}
void travel_list(L* pH) {
	L* p = pH->next;
	L* pBack;
	int i = 0;
	if (p->next == NULL || p == NULL) { return; }
	while (NULL != p->next) {
		pBack = p->next;
		if (p == pH->next) {
			p->next = NULL;
		}
		else {
			p->next = pH->next;
		}
		pH->next = p;
		p = pBack;
	}
	top_insert(pH, p);
}

int main() {
	int n, i, tmp, k, maxr;
	L* header1 = create_node(0);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header1, create_node(tmp));
	}

	//travel_list(header1);
	//sort1(header1, min_node(header1));
	//travel_list(header1);
	print_node1(header1);
	print_node2(header1);

	//print_node(header);
	return 0;
}

///////////////////////////////
while (scanf("%d", &tmp) != EOF) {
	tail_insert(header1, create_node(tmp));
}

typedef struct list_node {
	int data;
	struct list_node* next;
}L;
L* create_node(int data) {
	L* p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	p->data = data;
	p->next = NULL;
	return p;
}
void tail_insert(L* pH, L* new) {
	L* p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void top_insert(L* pH, L* new) {
	L* p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
void rev_node(L* pH, int k)//swap
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL) {
		if (p == pH) {
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else {
			back = pH;
			while (back->next != p) {
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void sort_list(L* header) {
	int sorted = 1;
	int count = 0;
	L* node = header->next;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	while (sorted) {
		sorted = 0;
		for (int i = 0; i < count - 1; i++) {
			node = header->next;
			for (int j = 0; j < i; j++) {
				node = node->next;
			}
			if (node->data > node->next->data) {
				rev_node(header, i + 1);
				sorted = 1;
			}
		}
	}
}
void sort1(L* header,int min) {
	L* ph = header;
	L* p =header;
	L* p2 =  p->next;
	L* prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == min) {
			prev->next = p->next;
			p->next = p2;
			ph->next = p;
			return 0;
		}
	}
	//printf("Delete Failed\n");
	return -1;
}
void remove_duplicates(L* pH) {
	L* current = pH->next;
	L* runner = NULL;
	L* prev = NULL;

	while (current != NULL) {
		runner = current->next;
		prev = current;

		while (runner != NULL) {
			if (current->data == runner->data) {
				L* temp = runner;
				prev->next = runner->next;
				runner = runner->next;
				free(temp);
			}
			else {
				prev = runner;
				runner = runner->next;
			}
		}
		current = current->next;
	}
}
int delete_list_node(L* pH, int data) {
	L* p = pH;
	L* prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == data) {
			if (p->next != NULL) {
				prev->next = p->next;
				free(p);
			}
			else {
				prev->next = NULL;
				free(p);
			}
			return 0;
		}
	}
	//printf("Delete Failed\n");
	return -1;
}

int min_node(L* pH) {
	L* p = pH;
	L* prev = NULL;
	int min = 32767;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data <min) {
			min = p->data;
		}
	}
	return min;
}
int minr_node(L* pH,int m,L*pH2) {
	L* p = pH;
	L* prev = NULL;
	int cnt = 0;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data < m) {
			tail_insert(pH2, create_node(p->data));
		}
		else if (p->data > m) {
			cnt++;
		}
	}
	return cnt;
}
void travel_list(L* pH) {
	L* p = pH->next;
	L* pBack;
	int i = 0;
	if (p->next == NULL || p == NULL) { return; }
	while (NULL != p->next) {
		pBack = p->next;
		if (p == pH->next) {
			p->next = NULL;
		}
		else {
			p->next = pH->next;
		}
		pH->next = p;
		p = pBack;
	}
	top_insert(pH, p);
}

int main() {
	int n, i, tmp, k,maxr;
	L* header1 = create_node(0);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header1, create_node(tmp));
	}
	sort1(header1,min_node(header1));
	//travel_list(header1);
	print_node(header1);

	//print_node(header);
	return 0;
}

//////51A/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* p;

double parse_expression();

double parse_number() {
	double num = 0;
	while (isdigit(*p)) {
		num = num * 10 + *p - '0';
		p++;
	}
	return num;
}

double parse_parenthesis() {
	if (*p == '(') {
		p++;
		double result = parse_expression();
		if (*p == ')') {
			p++;
			return result;
		}
	}
	return parse_number();
}

double parse_term() {
	double left = parse_parenthesis();
	while (*p == '*' || *p == '/') {
		char op = *p++;
		double right = parse_parenthesis();
		if (op == '*') {
			left *= right;
		}
		else {
			left /= right;
		}
	}
	return left;
}

double parse_expression() {
	double left = parse_term();
	while (*p == '+' || *p == '-') {
		char op = *p++;
		double right = parse_term();
		if (op == '+') {
			left += right;
		}
		else {
			left -= right;
		}
	}
	return left;
}

int main() {
	char expression[101];
	while (fgets(expression, sizeof(expression), stdin)) {
		p = expression;
		double result = parse_expression();
		printf("%.3f\n", result);
	}
	return 0;
}



typedef struct list_node {
	int data;
	struct list_node* next;
}L;
L* create_node(int data) {
	L* p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	p->data = data;
	p->next = NULL;
	return p;
}
void tail_insert(L* pH, L* new) {
	L* p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void print_node(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
int delete_list_node(L* pH, int data) {
	L* p = pH;
	L* prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == data) {
			if (p->next != NULL) {
				prev->next = p->next;
				free(p);
			}
			else {
				prev->next = NULL;
				free(p);
			}
			return 0;
		}
	}
	//printf("Delete Failed\n");
	return -1;
}
void remove_duplicates(L* pH) {
	L* current = pH->next;
	L* runner = NULL;
	L* prev = NULL;

	while (current != NULL) {
		runner = current->next;
		prev = current;

		while (runner != NULL) {
			if (current->data == runner->data) {
				L* temp = runner;
				prev->next = runner->next;
				runner = runner->next;
				free(temp);
			}
			else {
				prev = runner;
				runner = runner->next;
			}
		}
		current = current->next;
	}
}


int main() {
	int n, i, tmp, k;
	L* header1 = create_node(0);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header1, create_node(tmp));
	}

	remove_duplicates(header1);

	print_node(header1);

	//release
	L* current = header1;
	L* next = NULL;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	//print_node(header);
	return 0;
}

/////////////////



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertNode(Node** head, int data) {
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

int isSubsequence(Node* A, Node* B) {
	Node* p1 = A, * p2 = B;

	while (p1 != NULL && p2 != NULL) {
		if (p1->data == p2->data) {
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			p1 = p1->next;
		}
	}

	if (p2 == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void print_node(Node* pH) {
	Node* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
int main() {
	Node* A = NULL, * B = NULL;
	char buffer[1024];
	int value;

	gets(buffer);
	char* token = strtok(buffer, "  ");
	token = strtok(NULL, " \n"); // 跳过序列描述部分
	while (token != NULL) {

		sscanf(token, "%d", &value);
		insertNode(&A, value);
		token = strtok(NULL, "\n ");
	}
	insertNode(&A, 0);

	gets(buffer);
	gets(buffer);
	token = strtok(buffer, "  ");
	token = strtok(NULL, " \n"); // 跳过序列描述部分
	while (token != NULL) {
		sscanf(token, "%d", &value);
		insertNode(&B, value);
		token = strtok(NULL, "  ");
	}

	if (isSubsequence(A, B)) {
		printf("是\n");
	}
	else {
		printf("否\n");
	}

	return 0;
}


typedef struct list_node {
	int data;
	struct list_node* next;
}L;

int min3(int a, int b, int c) {
	int d=a;
	if (b < d) { d = b; }
	if (c < d) { d = c; }
	return d;
}
L* create_node(int data) {
	L* p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	p->data = data;
	p->next = NULL;
	return p;
}
void tail_insert(L* pH, L* new) {
	L* p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void top_insert(L* pH, L* new) {
	L* p = pH;
	new->next = p->next;
	p->next = new;
}
void rev_node(L* pH, int k)//swap
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL) {
		if (p == pH) {
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else {
			back = pH;
			while (back->next != p) {
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void sort_list(L* header) {
	int sorted = 1;
	int count = 0;
	L* node = header->next;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	while (sorted) {
		sorted = 0;
		for (int i = 0; i < count - 1; i++) {
			node = header->next;
			for (int j = 0; j < i; j++) {
				node = node->next;
			}
			if (node->data > node->next->data) {
				rev_node(header, i + 1);
				sorted = 1;
			}
		}
	}
}

void print_node(L* pH) {
	L* p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d \n", p->data);
}
int delete_list_node(L* pH, int data) {
	L* p = pH;
	L* prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == data) {
			if (p->next != NULL) {
				prev->next = p->next;
				free(p);
			}
			else {
				prev->next = NULL;
				free(p);
			}
			return 0;
		}
	}
	//printf("Delete Failed\n");
	return -1;
}

int nodef(L* pH1) {//noRepeat
	L* p1 = pH1;
	L* prev1 = NULL;
	int loc=0;

	int flag = 1;
	while (NULL != p1->next) {
		prev1 = p1;
		p1 = p1->next;
		loc++;
		if (loc > 1) {
			if (loc * loc - prev1->data != p1->data) {
				flag = 0;
				break;
			}
		}

	}
	return flag;
}


int main() {
	int n, i, tmp, k;
	L* header1 = create_node(0);
	L* header2 = create_node(0);
	scanf("输入线性表的节点数N=%d；", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header1, create_node(tmp));
	}


	if (nodef(header1)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	//print_node(header);
	return 0;
}
/////
	scanf("%d", &tmp);
	while (tmp!=-1) {
		tail_insert(header1, create_node(tmp));
		scanf("%d", &tmp);
	}
scanf("%d", &n);
	for (i = 0; i < n;i++) {
		scanf("%d", &tmp);
		tail_insert(header1, create_node(tmp));
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header2, create_node(tmp));
	}

int cnt = 0;
int node2(L* pH1, L* pH2) {//noRepeat
	L* p1 = pH1;
	L* prev1 = NULL;
	L* p2 = pH2;
	L* prev2 = NULL;

	prev2 = p2;
	p2 = p2->next;
	int flag = 1;
	while (NULL != p1->next ) {
		prev1 = p1;
		p1 = p1->next;
		 p2 = pH2;
		 prev2 = NULL;
		 prev2 = p2;
		 p2 = p2->next;
		 flag = 1;
		while (NULL != p2->next) {
			prev2 = p2;
			p2 = p2->next;
			if (p1->data == p2->data) {
				flag = 0;
				break;
			}

		}
		if (flag) {
			printf("%d ", p1->data);
			cnt++;
		}
	}
	return 1;
}

int node2(L* pH1, L* pH2) {
	L* p1 = pH1;
	L* prev1 = NULL;
	L* p2 = pH2;
	L* prev2 = NULL;

	prev1 = p1;
	p1 = p1->next;
	prev2 = p2;
	p2 = p2->next;
	while (NULL != p1->next && NULL != p2->next) {

		if (p1->data == p2->data) {
			printf("%d ", p2->data);
			prev1 = p1;
			p1 = p1->next;
		}
		else {
			//printf("%d f ", p2->data);
			if (p1->data > p2->data) {
				prev2 = p2;
				p2 = p2->next;
			}
			else {
				prev1 = p1;
				p1 = p1->next;
			}
		}
	}
	return 1;
}

int node3(L* pH1, L* pH2, L* pH3) {
	L* p1 = pH1;
	L* prev1 = NULL;
	L* p2 = pH2;
	L* prev2 = NULL;
	L* p3 = pH3;
	L* prev3 = NULL;
	prev1 = p1;
	p1 = p1->next;
	prev2 = p2;
	p2 = p2->next;
	prev3 = p3;
	p3 = p3->next;
	while (NULL != p1 && NULL != p2&& NULL != p3) {

		if (p1->data == p2->data&&p3->data == p2->data){
			printf("%d ", p2->data);
			prev1 = p1;
			p1 = p1->next;
			prev2 = p2;
			p2 = p2->next;
			prev3 = p3;
			p3 = p3->next;

		}
		else {
			//printf("%d %d %d f\n ", p1->data, p2->data, p3->data);
			if (p1->data == min3(p1->data, p2->data, p3->data)) {
				prev1 = p1;
				p1 = p1->next;
			}
			else if (p2->data == min3(p1->data, p2->data, p3->data)) {
				prev2 = p2;
				p2 = p2->next;
			}
			else if (p3->data == min3(p1->data, p2->data, p3->data)) {
				prev3 = p3;
				p3 = p3->next;
			}
		}
	}
	return 1;
}
void travel_list(L* pH) {
	L* p = pH->next;
	L* pBack;
	int i = 0;
	if (p->next == NULL || p == NULL) { return; }
	while (NULL != p->next) {
		pBack = p->next;
		if (p == pH->next) {
			p->next = NULL;
		}
		else {
			p->next = pH->next;
		}
		pH->next = p;
		p = pBack;
	}
	top_insert(pH, p);
}

typedef struct list_node {
	int data;
	struct list_node *next;
}L;

L *create_node(char * data) {
	L *p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	//strcpy(p->data , data);
	p->data= data;
	p->next = NULL;
	return p;
}

void rev_node(L* pH, int k)
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL) {
		if (p == pH) {
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else {
			back = pH;
			while (back->next != p) {
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void tail_insert(L *pH, L *new) {
	L *p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}

void top_insert(L *pH, L *new) {
	L *p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L *pH) {
	L *p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d ", p->data);
}

void sort_list(L* header) {
	int sorted = 1;
	int count = 0;
	L* node = header->next;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	while (sorted) {
		sorted = 0;
		for (int i = 0; i < count - 1; i++) {
			node = header->next;
			for (int j = 0; j < i; j++) {
				node = node->next;
			}
			if (node->data > node->next->data) {
				rev_node(header, i + 1);
				sorted = 1;
			}
		}
	}
}

int main() {
	int n,i,k;
	int  tmp;
	L *header = create_node(0);

	i = 0;
	scanf("%d", &tmp);
	while (tmp!=-1) {
		tail_insert(header, create_node(tmp));
		scanf("%d", &tmp);
	}


	//print_node(header);
	sort_list(header);
	print_node(header);
	return 0;
}




//////////////////
* typedef struct list_node {
	char data[30];
	struct list_node *next;
}L;

L *create_node(char * data) {
	L *p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	strcpy(p->data , data);
	p->next = NULL;
	return p;
}

void rev_node(L* pH, int k)
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL) {
		if (p == pH) {
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else {
			back = pH;
			while (back->next != p) {
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void tail_insert(L *pH, L *new) {
	L *p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}

void top_insert(L *pH, L *new) {
	L *p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L *pH) {
	L *p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%s ", p->data);
		p = p->next;
	}
	printf("%s ", p->data);
}

int main() {
	int n,i,k;
	char tmp[30];
	L *header = create_node("0");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", tmp);
		tail_insert(header, create_node(tmp));
	}
	
	print_node(header);
	return 0;
}
void tail_insert_n(L* pH, L* new) {//no echo tail insert
	L* p = pH;
	while (NULL != p->next) {
		if (strcmp(p->data, new->data)==0) {
			free(new);
			return 0;
		}
		p = p->next;
	}
	p->next = new;
}
typedef struct list_node {
	int data;
	struct list_node *next;
}L;

L *create_node(int data) {
	L *p = malloc(sizeof(L));
	if (NULL == p) {
		printf("malloc error!\n");
		return NULL;
	}
	memset(p, 0, sizeof(L));
	p->data = data;
	p->next = NULL;
	return p;
}
void tail_insert(L *pH, L *new) {
	L *p = pH;
	while (NULL != p->next) {
		p = p->next;
	}
	p->next = new;
}
void top_insert(L *pH, L *new) {
	L *p = pH;
	new->next = p->next;
	p->next = new;
}
void print_node(L *pH) {
	L *p = pH;
	p = p->next;
	while (NULL != p->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d\n", p->data);
}
int delete_list_node(L *pH, int data) {
	L *p = pH;
	L *prev = NULL;
	while (NULL != p->next) {
		prev = p;
		p = p->next;
		if (p->data == data) {
			if (p->next != NULL) {
				prev->next = p->next;
				free(p);
			}
			else {
				prev->next = NULL;
				free(p);
			}
			return 0;
		}
	}
	printf("Delete Failed\n");
	return -1;
}

void rev_node(L* pH, int k)//swap
{
	L* p = pH, * q, * back;
	int i = 0;
	while (i < k && p->next != NULL){
		p = p->next;
		i++;
	}
	q = p->next;
	if (q != NULL){
		if (p == pH){
			p->next = q->next;
			q->next = p;
			pH = q;
		}
		else{
			back = pH;
			while (back->next != p){
				back = back->next;
			}
			back->next = q;
			p->next = q->next;
			q->next = p;
		}
	}
}
void travel_list(L *pH) {
	L *p = pH->next;
	L *pBack;
	int i = 0;
	if (p->next == NULL || p == NULL) { return; }
	while (NULL != p->next) {
		pBack = p->next;
		if (p == pH->next) {
			p->next = NULL;
		}
		else {
			p->next = pH->next;
		}
		pH->next = p;
		p = pBack;
	}
	top_insert(pH, p);
}
int main() {
	int n,i,tmp,k;
	L *header = create_node(0);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tail_insert(header, create_node(tmp));
	}
	scanf("%d", &k);
	//print_node(header);
	rev_node(header, k);
	print_node(header);
	return 0;
}



for (i = 1; i < 10; i++) {
		tail_insert(header, create_node(i));
	}
	print_node(header);
	delete_list_node(header, 5);
	print_node(header);
	travel_list(header);
	print_node(header);
///////////////////////
void swap(char* a, char* b) {
	char c = *a;
	*a = *b;
	*b = c;
}
void bub(char* a ,int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) { swap(&a[j], &a[j + 1]); }
		}
	}
}
int isprime(int a) {
	int flag = 1;
	if (a < 2) { return 0; }
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
int a[6][32];
void rin() {
	for (int i = 0; i < 6; i++) {
		int num =0;
		for (int j = 0; j < 32; j++) {

			num++;
			if ((num - 1) % (int)pow(2,i) == 0) { num += (int)pow(2, i); }
			a[i][j] = num-1;
		}
	}
}
* 
* char trans(int x)
{

	if (x < 10){
		return '0' + x;
	}
	else{
		return 'a' + x - 10;
	}
}
//广度优先搜索
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 51
#define INF INT_MAX
int max4(int a, int b, int c, int d) {
	int e = a;
	if (b > e) { e = b; }
	if (c > e) { e = c; }
	if (d > e) { e = d; }
	return e;
}
int n, m, k;
int graph[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1][MAX_N + 1];
int flag = 0;
int sx, sy, ex, ey;

int wsearch(int x, int y,int d) {
	int ans;

	if (visited[y][x] ==0&&x>0&&y>0&&x<=m&&y<=n) {
		visited[y][x] = 1;
		//printf("%d,%d,%d 0\n", x, y, d);
		if (x == ex && y == ey) { flag = 1;  return d; }

		ans = max4(wsearch(x + 1, y, d + 1), wsearch(x - 1, y, d + 1), wsearch(x, y + 1, d + 1), wsearch(x, y - 1, d + 1));
		return ans;
	}
	else{
		//printf("%d,%d,%d 1\n", x, y, d);
		return 0;
	}

}

int main() {
	char temp[MAX_N + 1];
	int ans;
	while (scanf("%d %d", &n, &m) == 2) {

		flag = 0;
		getchar();
		for (int i = 1; i <= n; i++) {

			gets(temp);
			//printf("%s\n",temp);
			for (int j = 1; j <= m; j++) {
				if(temp[j-1]=='#'){
					visited[i][j] = 1;
				}
				else{
					visited[i][j] = 0;
				}
				if (temp[j-1] == 'W') {
					sx = j; sy = i;
				}
				if (temp[j-1] == 'G') {
					ex = j; ey = i;
				}
			}

		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				//printf("%d", visited[i][j]);
			}
			//printf("\n");
		}
		//printf("%d,%d\n%d,%d\n", sx, sy, ex, ey);
		ans=wsearch(sx,sy,0);  //
		if (flag == 0) {
			printf("Mission Failed\n");
		}
		else{
			printf("Good life\n"); //printf("%d\n", ans);
		}

	}
	return 0;
}





////////////////
* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生结构体，包含学号、姓名和成绩
typedef struct {
	int id;
	char name[32];
	int score;
} Student;

// 单链表结构体，包含头节点指针
typedef struct ListNode {
	Student data;
	struct ListNode* next;
} ListNode, * List;

// 创建节点，输入学生信息，返回新节点的指针
ListNode* create_node(int id, char* name, int score) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data.id = id;
	strcpy(node->data.name, name);
	node->data.score = score;
	node->next = NULL;
	return node;
}

// 建立单链表，返回头节点指针
List create_list() {
	ListNode* head = create_node(0, "", 0);
	ListNode* tail = head;
	int id, score;
	char name[32];
	while (1) {
		scanf("%d", &id);
		if (id == 0) {
			break;
		}
		scanf("%s%d", name, &score);
		ListNode* node = create_node(id, name, score);
		tail->next = node;
		tail = node;
	}
	return head;
}

// 按学号删除节点，成功返回1，失败返回0
int delete_node(List head, int id) {
	ListNode* prev = head, * curr = head->next;
	while (curr != NULL) {
		if (curr->data.id == id) {
			prev->next = curr->next;
			free(curr);
			return 1;
		}
		prev = curr;
		curr = curr->next;
	}
	return 0;
}

// 输出单链表
void print_list(List head) {
	ListNode* curr = head->next;
	while (curr != NULL) {
		printf("%d %s %d\n", curr->data.id, curr->data.name, curr->data.score);
		curr = curr->next;
	}
}

int main() {
	// 建立单链表
	List head = create_list();

	// 输入待删除的学号，调用删除记录的函数
	int id;
	scanf("%d", &id);
	if (!delete_node(head, id)) {
		printf("Not found\n");
	}

	// 显示删除操作后的链表信息
	print_list(head);

	// 释放单链表所占用的内存
	ListNode* curr = head, * temp;
	while (curr != NULL) {
		temp = curr->next;
		free(curr);
		curr = temp;
	}

	return 0;
}
* #include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
	dummy->next = NULL;
	ListNode* cur = dummy;

	while (l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}

	if (l1 != NULL) {
		cur->next = l1;
	}

	if (l2 != NULL) {
		cur->next = l2;
	}

	ListNode* newHead = dummy->next;
	free(dummy);

	// 反转单链表
	ListNode* prev = NULL;
	ListNode* temp;
	while (newHead != NULL) {
		temp = newHead->next;
		newHead->next = prev;
		prev = newHead;
		newHead = temp;
	}

	return prev;
}

int main() {
	int n, m;

	scanf("%d", &n);

	ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
	l1->next = NULL;
	ListNode* cur1 = l1;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = num;
		newNode->next = NULL;
		cur1->next = newNode;
		cur1 = cur1->next;
	}


	scanf("%d", &m);

	ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
	l2->next = NULL;
	ListNode* cur2 = l2;
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = num;
		newNode->next = NULL;
		cur2->next = newNode;
		cur2 = cur2->next;
	}

	ListNode* mergedList = mergeTwoLists(l1->next, l2->next);
	while (mergedList != NULL) {
		printf("%d ", mergedList->val);
		mergedList = mergedList->next;
	}

	// 释放内存
	ListNode* temp;
	while (l1 != NULL) {
		temp = l1->next;
		free(l1);
		l1 = temp;
	}
	while (l2 != NULL) {
		temp = l2->next;
		free(l2);
		l2 = temp;
	}
	while (mergedList != NULL) {
		temp = mergedList->next;
		free(mergedList);
		mergedList = temp;
	}

	return 0;
}
* #include <stdio.h>
#include <stdlib.h>

struct Student {
	int id;
	int score;
};

int cmp(const void* a, const void* b) {
	struct Student* pa = (struct Student*)a;
	struct Student* pb = (struct Student*)b;
	return pa->id - pb->id;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	struct Student a[1000], b[1000];

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(a[i].id), &(a[i].score));
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &(b[i].id), &(b[i].score));
	}

	int total = n + m;
	struct Student c[1000];
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}
	for (int i = n; i < total; i++) {
		c[i] = b[i - n];
	}

	qsort(c, total, sizeof(struct Student), cmp);

	for (int i = 0; i < total; i++) {
		printf("%d %d\n", c[i].id, c[i].score);
	}

	return 0;
}

* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义链表结构体
typedef struct student {
	int num;
	char name[20];
	int score;
	struct student* next;
} Student;

// 建立链表函数
Student* createList() {
	Student* head, * p, * q;
	head = (Student*)malloc(sizeof(Student));
	head->next = NULL;
	q = head;

	int num, score;
	char name[20];
	scanf("%d", &num);
	while (num != 0) {
		scanf("%s%d", name, &score);
		p = (Student*)malloc(sizeof(Student));
		p->num = num;
		strcpy(p->name, name);
		p->score = score;
		p->next = NULL;

		while (q->next != NULL && q->next->num < num) {
			q = q->next;
		}
		p->next = q->next;
		q->next = p;

		q = head;
		scanf("%d", &num);
	}
	return head;
}

// 插入学生记录函数
void insertRecord(Student* head) {
	int num, score;
	char name[20];
	scanf("%d%s%d", &num, name, &score);

	Student* p, * q;
	q = head;
	while (q->next != NULL && q->next->num < num) {
		q = q->next;
	}
	if (q->next != NULL && q->next->num == num) {
		printf("Record exists!\n");
		return;
	}

	p = (Student*)malloc(sizeof(Student));
	p->num = num;
	strcpy(p->name, name);
	p->score = score;
	p->next = q->next;
	q->next = p;
}

// 输出链表信息函数
void printList(Student* head) {
	Student* p = head->next;
	while (p != NULL) {
		printf("%d %s %d\n", p->num, p->name, p->score);
		p = p->next;
	}
}

// 主函数
int main() {
	Student* head = createList();
	insertRecord(head);
	printList(head);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义链表节点
typedef struct Node {
	char name[50]; //学生姓名
	int score; //学生成绩
	struct Node* next; //指向下一个节点的指针
} Node;

//计算班级平均分和最高分者的姓名和分数
void calculate(Node* head, int classNum,int num) {
	Node* p = head->next;
	float sum = 0;
	int maxScore = 0;
	char maxName[50];
	while (p != NULL) {
		sum += p->score;
		if (p->score > maxScore) {
			maxScore = p->score;
			strcpy(maxName, p->name);
		}
		p = p->next;
	}
	float avgScore = sum / num;
	printf("%d %.2f %s %d\n", classNum, avgScore, maxName, maxScore);
}

int main() {
	int m;
	scanf("%d", &m);
	//遍历每个班级
	for (int i = 1; i <= m; i++) {
		int n;
		scanf("%d", &n);
		Node* head = (Node*)malloc(sizeof(Node)); //创建头节点
		head->next = NULL; //初始化为空链表
		//读入每个学生的信息并插入链表
		for (int j = 1; j <= n; j++) {
			Node* p = (Node*)malloc(sizeof(Node));
			scanf("%s %d", p->name, &p->score);
			p->next = head->next;
			head->next = p;
		}
		calculate(head, i, n); //计算该班级的平均分和最高分者的姓名和分数
	}
	return 0;
}

////////////////////////////
void bubble(int* a, int n) {
	int i, k;
	int c;
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (a[k] > a[k + 1]) {
				c = a[k];
				a[k] = a[k + 1];
				a[k + 1] = c;
			}
		}
	}
}
int isnum(char ch) {
	int a = 0;
	a = (ch >= '0' && ch <= '9') ? 1 : 0;
	//if (ch == '.') { a = 2; }
	return a;
}

char* revstr(char* str) {
	char ans[1000];
	int i;
	for (i = 0; i < strlen(str); i++) {
		ans[i] = str[strlen(str) - i - 1];
	}
	ans[i] = '\0';
	return ans;
}

int isprime(long a) {//really fixed
	int i, m;
	int flag;
	i = a;
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <= sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}


char* mixs(char* a, char* b) {
	char ans[30000];
	int i, j;
	i = 0;
	for (j = 0; j < strlen(a); j++) {
		ans[i] = a[j];
		i++;
	}
	for (j = 0; j < strlen(b); j++) {
		ans[i] = b[j];
		i++;
	}
	ans[i] = '\0';
	return ans;

}

int leap(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		return(1);
	}
	else { return(0); }
}
* //////////////////////////////////////
char c;
	for (c = getchar(); getchar() != '#'; c = getchar()) {
		putchar(c);
	}
	return 0;

int main() {
	int day[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31}, { 0,31,29,31,30,31,30,31,31,30,31,30,31 } };
	int d, m, y;
	int sum, ed, em, ey, cy, ans;
	scanf("%d.%d.%d", &y, &m, &d);
	sum = 0;
	for (em = 1; em < m; em++) {
		sum = sum + day[leap(y)][em];
		//printf("%d\n ", day[leap(ey)][em]);
	}
	sum = sum + (d);
	//printf("%d\n ", (day[leap(ey)][em] - d));
	printf("%d\n", sum);

	return 0;
}

char* binary(int num) {
	char ans[100];
	int i = 0;
	while(i<8) {
		ans[i] = num % 2 + '0';
		num = num / 2;
		i++;
	}
	ans[i] = '\0';
	strcpy(ans, revstr(ans));
	return ans;
}
int main() {
	int i, n;
	int num[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		printf("%s\n", binary(num));

		//01011010
		//00110110
		//01001100
	}

	return 0;
}
//////////////////////////////////

int leap(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		return(1);
	}
	else { return(0); }
}

int main() {
	int day[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31}, { 0,31,29,31,30,31,30,31,31,30,31,30,31 } };
	int d, m, y;
	int sum, ed, em, ey,cy,ans;
	scanf("%d%d%d", &y, &m, &d);
	while (d != 0 || m != 0 || y != 0) {
		sum = 0;
		for (ey = 2022; ey > y; ey--) {
			sum = sum + 365 + leap(ey);
			//printf("%d\n ", 365 + leap(ey));
		}
		for (em = 12; em > m; em--) {
			sum = sum + day[leap(ey)][em];
			//printf("%d\n ", day[leap(ey)][em]);
		}
		sum = sum + (day[leap(ey)][em] - d);
		//printf("%d\n ", (day[leap(ey)][em] - d));
		ans = ((21000 + (6 - sum) - 1) % 7) + 1;

		printf("%d\n", ans);
		scanf("%d%d%d", &y, &m, &d);
	}

	return 0;
}


char* revstr(char* str) {
	char ans[1000];
	int i;
	for (i = 0; i < strlen(str); i++) {
		ans[i] = str[strlen(str) - i - 1];
	}
	ans[i] = '\0';
	return ans;
}
char* add(char* str) {
	char ans[100];
	int i,sum;
	sum = 0;
	for (i = 0; i < strlen(str); i++) {
		sum = sum + str[i] - '0';
	}
	i = 0;
	while (sum > 0) {
		ans[i] = sum % 10 +'0';
		sum = sum / 10;
		i++;
	}
	ans[i] = '\0';
	strcpy(ans, revstr(ans));
	return ans;
}

int main() {
	char num[20];
	gets(num);
	while (strcmp(num, "0") != 0) {
		while (strlen(num) > 1) {
			strcpy(num, add(num));
		}
		printf("%s\n", num);
		gets(num);
	}

	return 0;
}

void bubble(int* a, int n) {
	int i, k;
	int c;
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (a[k] > a[k + 1]) {
				c = a[k];
				a[k] = a[k + 1];
				a[k + 1] = c;
			}
		}
	}
}

char ans[15][100];
void bubble2(int n) {
	int i, m;
	char tmp[100];
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (strcmp(ans[m], ans[m + 1]) > 0) {
				strcpy(tmp, ans[m]);
				strcpy(ans[m], ans[m + 1]);
				strcpy(ans[m + 1], tmp);
			}
		}
	}
}
int main() {
	int i,n;
	char crap[100];
	scanf("%d", &n);
	while(n!=0) {
		gets(crap);
		for (i = 0; i < n; i++) {
			gets(ans[i]);
		}
		bubble2(n);
		for (i = 0; i < n; i++) {
			printf("%s\n", ans[i]);
		}
		scanf("%d", &n);
	}
}
char* revstr(char* str) {
	char ans[1000];
	int i;
	for (i = 0; i < strlen(str); i++) {
		ans[i] = str[strlen(str) - i - 1];
	}
	ans[i] = '\0';
	return ans;
}
int main() {
	char a[100], b[100];
	scanf("%s%s", a, b);
	strcpy(a, revstr(a));
	strcpy(b, revstr(b));
	printf("%s%s", a, b);
	return 0;
}


int main() {
	char ans[10000],tmmp[10];
	int i=0, j, tmp=0;
	scanf("%d", &tmp);
	while (tmp != 0) {
		j = 6; tmmp[7] = '\0';
		while (j >= 0) {
			tmmp[j] = tmp % 2+'0';
			tmp = tmp / 2;
			j--;
		}
		//printf("%s\n", tmmp);
		strcpy(tmmp, revstr(tmmp));
		tmp = 0;
		for (j = 0; j < 7;j++) {
			tmp = tmp*2 + tmmp[j]-'0';
		}
		ans[i] = tmp;
		i++;
		//printf("%c\n", tmp);
		scanf("%d", &tmp);
	}
	ans[i] = '\0';
	printf("%s\n", ans);
	return 0;
}

char a[10000],b[10000];
char p1[100][20], p2[100][20];
int isen(char ch) {
	int a = 0;
	if (ch >= 'a' && ch <= 'z') { a = 1; }
	return a;
}
void bubble2(int n) {
	int i, m;
	char tmp[100];
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (strlen(p1[m]) <strlen(p1[m + 1])) {
				strcpy(tmp, p1[m]);
				strcpy(p1[m], p1[m + 1]);
				strcpy(p1[m + 1], tmp);
			}
		}
	}
}
int main() {
	int i, i1, i2, p;
	gets(a);
	gets(b);
	i1 = 0; i2 = 0; p = 0;
	for (i = 0; i < strlen(a); i++) {
		if (isen
(a[i])==1) {
			p1[i1][p] = a[i];
			p++;
		}
		else {
			p1[i1][p] = '\0';
			i1++;
			p = 0;
		}
	}
	p1[i1][p] = '\0';
	i1++;
	//printf("1\n");
	bubble2(i1);
	p = 0;
	for (i = 0; i < strlen(b); i++) {
		if (isen(b[i]) == 1) {
			p2[i2][p] = b[i];
			p++;
		}
		else {
			p2[i2][p] = '\0';
			i2++;
			p = 0;
		}
	}
	p2[i2][p] = '\0';
	i2++;
	//printf("2\n");
	for (i = 0; i < i1; i++) {
		for (p = 0; p < i2; p++) {
			//printf("%s %s\n", p1[i],p2[p]);
			if (strcmp(p1[i], p2[p])==0) {
				printf("%s\n", p1[i]);
				return 0;
			}
		}
	}
	return 0;
}

* int a[32767];
	int n, tmp, num, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		a[i] = 1;
	}
	num = n; i = 1; tmp = 0;
	while (num > 1) {
		if (a[i] == 1) {
			tmp++;
			if (tmp == 4) {
				a[i] = 0;
				tmp = 0;
				num--;
			}
		}
		i++;
		if (i > n) { i = 1; }
	}
	for (i = 1; i <= n; i++) {
		if (a[i] == 1) { printf("%d\n", i); }
	}

* float a, b, c,max;
	scanf("%f%f%f", &a,&b,&c);
	max = a;
	if (b > max) { max = b; }
	if (c > max) { max = c; }
	printf("%.3f\n%.3f\n", max,max);
* int c1[1010], c2[1010], a1[1010], b1[1010];
int main()
{
	char a[1010], b[1010];
	int i, j, k, l1, l2, t1, t2, a2[1010], b2[1010];
	while (scanf("%s%s", a, b) != EOF)
	{
		for (i = 0; i < 1000; i++)//初始化为0跟memset一样的道理
			a1[i] = a2[i] = b1[i] = b2[i] = c1[i] = c2[i] = 0;
		l1 = strlen(a), l2 = strlen(b);//计算长度
		for (i = 0, j = 0; i < l1; i++, j++)//标记小数点
			if (a[i] == '.')
				break;
		t1 = i;//记录a的小数点位置
		for (i = t1 - 1, j = 0; i >= 0; i--, j++)//整数部分和大数加法一样逆序存方便计算
			a1[j] = a[i] - '0';
		for (i = t1 + 1, j = 0; i < l1; i++, j++)//小数部分直接存，方便计算，自己想想为啥把
			a2[j] = a[i] - '0';
		//同理计算b
		for (i = 0; i < l2; i++)
			if (b[i] == '.')
				break;
		t2 = i;//标记小数点
		for (i = t2 - 1, j = 0; i >= 0; i--, j++)
			b1[j] = b[i] - '0';//整数部分
		for (i = t2 + 1, j = 0; i < l2; i++, j++)//小数部分
			b2[j] = b[i] - '0';
		int x = 0, y = 0;
		//计算小数部分
		for (i = 500; i >= 0; i--)
		{
			x = a2[i] + b2[i] + x;
			c2[i] = x % 10;//存结果
			x = x / 10;
		}
		//计算整数部分，不要把x初始化了 有可能十分位计算完要进位
		//如：1.11+9.9=11.01，这个时候小数点后面1+9等于10要对个位进位
		for (i = 0; i < 500; i++)
		{
			x = x + a1[i] + b1[i];
			c1[i] = x % 10;
			x = x / 10;
		}

		for (i = 500; i >= 0; i--)
			if (c1[i] != 0)
				break;
		//特判整数部分为0
		if (i == -1)
			printf("0");
		for (; i >= 0; i--)
			printf("%d", c1[i]);//整数部分
		for (i = 500;; i--)
			if (c2[i] != 0)
				break;
		int f = 0;
		for (j = 0; j <= i; j++)
		{
			if ((j == 0 && c2[0] != 0) || i > 0 && f == 0)//找小数点的位置还要判断是否存在小数部分
				printf("."), f = 1;
			printf("%d", c2[j]);
		}

		printf("\n");
	}
}
int isnum(char ch) {
	int a = 0;
	if (ch >= '0' && ch <= '9') { a = 1; }
	//if (ch == '.') { a = 2; }
	return a;
}
int main() {
	char pop[75][15];
	int i, m;
	for (i =0; i < 72; i++) {
		//scanf("%s", pop[i]);
		gets(pop[i]);
	}
	for (i = 33; i < 72; i++) {
		printf("%d ", i - 33);
		for (m = 0; m < strlen(pop[i]); m++) {
			if (isnum(pop[i][m]) == 1) { printf("%c", pop[i][m]); }
		}
		printf("\n");
	}
	return 0;
}
* int maxi(int a, int b) {
	if (a > b) { return a; }
	else { return b; }
}
int isnum(char ch) {
	int a = 0;
	if (ch >= '0' && ch <= '9') { a = 1; }
	if (ch == '.') { a = 2; }
	return a;
}
int main() {
	int m, k, i;
	char a[10000], b[10000], ans[10000];
	int tmp, s, up, lena1, lena2, lenb1, lenb2, t1, t2, t3, s3, f1, f2, pos;
	while (scanf("%s %s", a, b) != EOF) {

		for (i = 0; i < strlen(a); i++) {
			if (a[i] == '.') {
				//printf("v1\n");
				break;
			}
		}
		if (i == strlen(a)) { lena1 = strlen(a); lena2 = 0; }
		else { lena1 = i; lena2 = strlen(a) - lena1 - 1; }

		for (i = 0; i < strlen(b); i++) {
			if (b[i] == '.') {
				//printf("v2\n");
				break;
			}
		}
		if (i == strlen(b)) { lenb1 = strlen(b); lenb2 = 0; }
		else { lenb1 = i; lenb2 = strlen(b) - lenb1 - 1; }

		t1 = maxi(lena1, lenb1);
		t2 = maxi(lena2, lenb2);
		t3 = t1 + t2 + 1;
		ans[t3 + 1] = '\0';
		//ans[0] = '0';
		f1 = strlen(a) - 1;
		f2 = strlen(b) - 1;
		//printf("%d %d %d %d\n", lena1, lena2, lenb1, lenb2);
		up = 0;
		pos = 1;
		while (t3 >= 0) {
			if (t3 != t1 + 1) {
				if (t3 > t1 + 1) {
					if (t3 - t1 - 1 > lena2) { f1 = strlen(a); a[f1] = '0'; }
					if (t3 - t1 - 1 > lenb2) { f2 = strlen(b); b[f2] = '0'; }
				}
				if (t3 < t1 + 1) {
					if (f1 < 0) { f1 = 0; a[f1] = '0'; }
					if (f2 < 0) { f2 = 0; b[f2] = '0'; }
				}
				ans[t3] = a[f1] + b[f2] + up - '0';
				up = 0;
				if (isnum(ans[t3]) == 0) { up = 1; ans[t3] -= 10; }
				if (ans[t3] != '0' && t3 > t1 - 1 && pos == 1) { ans[t3 + 1] = '\0'; pos = 0; }
				f1--; f2--; t3--;
			}
			else {
				ans[t3] = '.';
				t3--;
				if (lena2 != 0) { f1--; }
				if (lenb2 != 0) { f2--; }
			}
		}

		if (ans[0] = '0') {
			//printf("s0\n");
			for (i = 1; i < strlen(ans); i++) {
				printf("%c", ans[i]);
			}
			printf("\n");
		}
		else {
			//printf("s1\n");
			printf("%s\n", ans);
		}
	}
	return 0;
}
int isnum(char ch) {
	int a = 0;
	if (ch >= '0' && ch <= '9') { a = 1; }
	//if (ch == '.') { a = 2; }
	return a;
}
int main() {
	char pop[75][15];
	int i, m;
	for (i = 0; i < 72; i++) {
		scanf("%s", pop[i]);
	}
	for (i = 33; i < 72; i++) {
		printf("%d ", i - 33);
		for (m = 0; m < strlen(pop[i]); m++) {
			if (isnum(pop[i][m]) == 1) { printf("%c", pop[i][m]); }
		}
		printf("\n");
	}
	return 0;
}
* 	//y = -0.0123x4 + 0.7825x3 - 27.266x2 + 737.66x + 119133
	long long x, y;
	x = 2037;
	y = (-0.0123 * x * x * x * x) + (0.7825 * x * x * x) - (27.266 * x * x) + (737.66 * x) + 119133;
	printf("%lld", y);
*
*
*
*
* char* revstr(char* str){
	char ans[1000];
	int i;
	for (i = 0; i < strlen(str); i++) {
		ans[i] = str[strlen(str) - i - 1];
	}
	ans[i] = '\0';
	return ans;
}

int main() {
	char str[1000];
	while (gets(str) != NULL) {
		if (strcmp(str, revstr(str)) == 0) {
			//printf("%s ",revstr(str));
			printf("Yes\n");
		}
		else {
			//printf("%s ", revstr(str));
			printf("No\n");
		}
	}
	return 0;
}
int maxi(int a, int b) {
	if (a > b) { return a; }
	else { return b; }
}
int isen(char ch) {
	int a = 0;
	if (ch >= 'A' && ch <= 'Z') { a = 1; }
	return a;
}
int main() {
	int m, k, i;
	char a[10000], b[10000], ans[10000];
	int tmp, s, up, t1, t2, t3;
	//scanf("%d", &m);
	while(scanf("%s %s", a, b)!=EOF) {
		//scanf("%s %s", &a, &b);
		t1 = strlen(a) - 1;
		t2 = strlen(b) - 1;
		t3 = maxi(t1, t2);
		ans[t3 + 1] = '\0';
		//ans[0] = '0';
		up = 0;
		while (t1 >= 0 || t2 >= 0) {
			if (t1 < 0) { t1 = 0; a[t1] = 'A'; }
			if (t2 < 0) { t2 = 0; b[t2] = 'A'; }
			ans[t3] = a[t1] + b[t2] + up - 'A';
			up = 0;
			if (isen(ans[t3]) == 0) { up = 1; ans[t3] -= 26; }
			t1--; t2--; t3--;
		}
		for (i = 0; i < strlen(ans); i++) {
			if (ans[i] == 'A') { continue; }
			else { break; }
		}
		if (up == 1) { printf("B"); }
		while (i < strlen(ans)) {
			printf("%c", ans[i]);
			i++;
		}
		printf("\n");
	}
	return 0;
}

	char a[10000];
	char b[100];
	int i1, i2,cnt;
	scanf("%s%s", a, b);
	cnt = 0;
	for (i1 = 0; i1 < strlen(a); i1++) {
		if (a[i1] == b[0]) {
			for (i2 = 1; i2 < strlen(b); i2++) {
				if (a[i1 + i2] != b[i2]) { i1 += i2; break; }
			}
			if (i2 == strlen(b)) { i1 = i1 +  i2 - 1; cnt++; }
		}
	}
	printf("%d\n", cnt);
int main() {
	int a11, a12, a13, a21, a22, a23;
	int b11, b12, b21, b22, b31, b32;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &a11, &a12, &a13, &a21, &a22, &a23, &b11, &b12, &b21, &b22, &b31, &b32);
	printf("%d %d\n%d %d\n", a11 * b11 + a12 * b21 + a13 * b31, a11 * b12 + a12 * b22 + a13 * b32, a21 * b11 + a22 * b21 + a23 * b31, a21 * b12 + a22 * b22 + a23 * b32);

	return 0;
}
	int a[32767];
	int n, tmp,num, i;
	while(scanf("%d", &n)!=EOF) {
		for (i = 1; i <= n; i++) {
			a[i] = 1;
		}
		num = n; i = 1; tmp = 0;
		while (num > 1) {
			if (a[i] == 1) {
				tmp++;
				if (tmp == 3) {
					a[i] = 0;
					tmp = 0;
					num--;
				}
			}
			i++;
			if (i > n) { i = 1; }
		}
		for (i = 1; i <= n; i++) {
			if (a[i] == 1) { printf("%d\n", i); }
		}
	}
int isprime(long a) {//really fixed
	int i, m;
	int flag;
	i = a;
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <= sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
int isprime2(int* s, int num, int a) {
	int i,flag=0;
	for (i = 0; i < num; i++) {
		if (a == s[i]) { flag = 1; break; }
		//if (a < s[i]) { break; }
	}
	return flag;
}
int main() {
	int a[1000], i, num = 0, c, d;
	int b[3000];
	int  x[10];
	int i1, i2, i3, i4, i5, i6, i7, i8, i9;
	int ans=0, sum;
	scanf("%d,%d", &c, &d);
	for (i = c; i <= d; i++) {
		if (isprime(i) == 1) {
			a[num] = i;
			num++;
			//printf("%d %d\n", i, isprime2(a, num, i));
		}
	}
	//for (i = c; i <= d; i++) {printf("%d %d\n", i, isprime2(a, num, i));}
	for (i5 = 0; i5 < num; i5++) {
		x[5] = a[i5]; sum = x[5] * 3;
		for (i1 = 0; i1 < num; i1++) {
			x[1] = a[i1];
			x[9] = sum - x[1] - x[5];
			for (i3 = 0; i3 < num; i3++) {
				x[3] = a[i3];
				x[7] = sum - x[3] - x[5];
				x[2] = sum - x[1] - x[3];
				x[4] = sum - x[1] - x[7];
				x[6] = sum - x[4] - x[5];
				x[8] = sum - x[2] - x[5];
				if (isprime2(a, num, x[9]) == 0) { continue; }
				if (isprime2(a, num, x[7]) == 0) { continue; }
				if (isprime2(a, num, x[2]) == 0) { continue; }
				if (isprime2(a, num, x[4]) == 0) { continue; }
				if (isprime2(a, num, x[6]) == 0) { continue; }
				if (isprime2(a, num, x[8]) == 0) { continue; }
				if (x[7] > x[3]) { continue; }
				if (x[9] > x[1]) { continue; }
				if (x[1] > x[3]) { continue; }
				//printf("s1\n");
				for (i = 0 ; i < 3000; i++) {b[i] = 0;}
				for (i = 1; i <=9; i++) {
					if(b[x[i]]==0) {b[x[i]] ++;}
					else { break; }
				}
				if (i==10) {
					ans++;
					//printf("%5d%5d%5d\n%5d%5d%5d\n%5d%5d%5d\n\n", x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9]);
				}
			}
		}
	}
	printf("共%d个素数幻方\n", ans);
	return 0;
}
printf("%5d%5d%5d\n%5d%5d%5d\n%5d%5d%5d\n", x1, x2, x3, x4, x5, x6, x7, x8, x9);
*int strcmpp(char* a, char* b) {
	int i,tmp;
	for (i = 0; i < strlen(a); i++) {
		tmp = a[i] - b[i];
		if (tmp != 0) { return tmp; }
	}
	return 0;
}
int main() {
	int n, i;
	char a[1000], b[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", a, b);
		printf("%d\n", strcmpp(a, b));
	}

	return 0;
}
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int isprime(long a) {//really fixed
	int i, m;
	int flag;
	i = a;
	//scanf_s("%d", &n);
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <= sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
int main() {
	long a, b;
	long long ans = 0;
	long i;
	//primecheck();
	//for (i = 0; i < cnt; i++) {printf("%d\n", prime[i]);}
	while (scanf("%ld %ld", &a, &b) != EOF) {
		if (a > b) { swap(&a, &b); }
		ans = 0;
		for (i = a; i <= b; i++) {
			if (isprime(i)) {
				ans = ans + i;
				printf("%d\n", i);
			}
		}
		//printf("%lld\n", ans);
	}
	return 0;
}


*
*
* 	int a[32767];
	int i, tmp, max, maxd;
	max = -1;
	for (i = 0; i < 32767; i++) {
		a[i] = 0;
	}
	for (i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		a[tmp]++;
		if (a[tmp] > max) { maxd = tmp; max = a[tmp]; }
	}
	printf("%d\n%d", maxd, max);


void bubble(int *a,int n) {
	int i, k;
	double c;
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (a[k] < a[k + 1]) {
				c = a[k];
				a[k] = a[k + 1];
				a[k + 1] = c;

			}
		}
	}
}
int main(){
	int i;
	int a[32767];
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	bubble(a,10);
	for (i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
* 	int a[1000];
	int i, cnt, max, min,sum;
	double avg;
	i = 0; min = 32767; max = -32767; sum = 0;
	scanf("%d", &a[i]);
	while (a[i] != 0) {
		sum = sum + a[i];
		if (a[i] > max) { max = a[i]; }
		if (a[i] < min) { min = a[i]; }
		i++;
		scanf("%d", &a[i]);
	}
	avg = sum / (double)i;
	printf("Num=%d\nMax=%d\nMin=%d\nAvg=%.3lf\n", i, max, min, avg);
char ans[100][10];
void bubble2(int n) {
	int i, m;
	char tmp[100];
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (strcmp(ans[m], ans[m + 1]) > 0) {
				strcpy(tmp, ans[m]);
				strcpy(ans[m], ans[m + 1]);
				strcpy(ans[m + 1], tmp);
			}
		}
	}
}
int main() {
	char dic[1000][10];

	char tmp[100];
	int b[1000][26],tb[26];
	int i, m, n, cnt,num;
	i = 0; cnt = 0;
	scanf("%s", &dic[i]);
	while (strcmp(dic[i], "******") != 0) {
		for (m = 0; m < 26; m++) {
			b[i][m] = 0;
		}
		for (m = 0; m < strlen(dic[i]); m++) {
			b[i][dic[i][m] - 'a']++;
		}
		i++;
		scanf("%s", &dic[i]);
		cnt++;
	}
	while (scanf("%s", &tmp) != EOF) {
		num = 0;
		for (i = 0; i < cnt; i++) {
			for (m = 0; m < 26; m++) {
				tb[m] = 0;
			}
			for (m = 0; m < strlen(tmp); m++) {
				tb[tmp[m] - 'a']++;
			}
			for (m = 0; m < 26; m++) {
				if (tb[m] != b[i][m]) { break; }
			}
			if (m == 26) {
				strcpy(ans[num], dic[i]);
				//printf("%s\n", dic[i]);
				num++;
			}
		}
		bubble2(num);
		if (num > 0) {
			for (m = 0; m < num - 1; m++) {
				printf("%s ", ans[m]);
			}
			printf("%s\n", ans[m]);
		}
		else { printf(":(\n"); }
	}

	return 0;
}

* int m, n, i;
	int tm, tn, cnt;
	char a[10000], b[10000];
	//scanf("%d %d", &m, &n);
	gets(a);
	gets(b);
	m = strlen(a);
	n = strlen(b);
	tm = 0, tn = 0; cnt = 0;
	while (tm < m || tn < n) {
		if(tn!=9999&&tm!=9999) {
			if (a[tm] > b[tn]) { printf("%c", b[tn]); tn++; }
			else { printf("%c", a[tm]); tm++; }
		}
		else {
			if (tn == 9999) { printf("%c", a[tm]); tm++; }
			if (tm == 9999) { printf("%c", b[tn]); tn++; }
		}
		if (tn >= n) { tn=9999; b[tn] =255; }
		if (tm >= m) { tm=9999; a[tm] =255; }
	}
	printf("\0");
	return 0;
* int main() {
	int b[1000];//bucket
	int a[10];//input(0-999)
	int i;
	for (i = 0; i < 1000; i++) {//initialize
		b[i] = 0;
	}
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);//input
		b[a[i]]++;//into bucket
	}
	for (i = 0; i < 1000; i++) {
		while (b[i] > 0) {
			printf("%d\n", i);//output
			b[i]--;//case echo
		}
	}
	return 0;
}
* char s[100], ss[100],c;
	int i;
	while (gets(s) != NULL) {
		for (i = 0; i < strlen(s); i++) {
			c = s[i];
			if (s[i] >= 'A' && s[i] <= 'Z') { c = c + 32; }
			ss[i] = c;
		}
		for (i = 0; i < strlen(s)-3; i++) {
			if (ss[i] == 's' ) {
				if (ss[i + 1] == 'a' && ss[i + 2] == 'l' && ss[i + 3] == 't') {
					printf("%s\n", s); break;
				}
			}
			else { continue; }
		}
	}
	return 0;
* int factcnt(int a) {
	int c = 0, i;
	for (i = 1; i <= a; i++) {
		if (a % i == 0 ) {
			c++;
		}
	}
	return(c);
}
int main() {
	int n, ans, max, i,tmp;
	while (scanf("%d", &n) != EOF) {
		max = 0; ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			if (factcnt(tmp) > max || factcnt(tmp) == max && tmp < ans) {
				max = factcnt(tmp); ans = tmp;
			}
		}
		printf("%d\n", ans);
	}
}
* 	int m, n ,i ;
	int tm, tn,cnt;
	int a[1000], b[1000];
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	tm = 0, tn = 0; cnt = 0;
	while (tm < m && tn < n) {
		if (a[tm] == b[tn]) { cnt++; tm++; tn++; }
		if (a[tm] > b[tn]) { tn++; }
		if (a[tm] < b[tn]) { tm++; }
	}
	printf("%d\n", cnt);
	return 0;
* 	long long n, i, m,tmp,cnt,tmpp,cntt;
	long a[7],ans;
	scanf("%lld", &n);
	cnt = 0; cntt = 0;
	for (i = pow(10,n-1); i < pow(10, n); i++) {
		for (m = 1; m <= n; m++) {
			a[m] = 0;
		}
		tmp = i;
		for (m = n; m > 0; m--) {
			tmpp = tmp % 10;
			if (tmpp == m||a[tmpp]>0||tmpp>n||tmpp==0) { break; }
			a[tmpp]++;
			tmp = tmp / 10;
		}
		if (m != 0) { continue; }
		else {
			if (cnt == 4) {
				cnt = 0; printf("%lld\n", i); cntt++;
			}
			else {
				cnt++; printf("%lld ", i); cntt++;
			}
		}
	}
	printf("\ns=%lld\n", cntt);

* long a, b,i;
	scanf("%ld", &a);
	b = a * a;
	i = 10;
	while (i <= b) { i = i * 10; }
	i = i / 10;
	while (b >= a) {
		b = b % i;
		i = i / 10;
		if (b == a) { printf("是守形数\n"); break; }
	}
	if (b != a) { printf("不是守形数\n");}

* 	char str[10];
	char num[20];
	int i, tmp;
	char anss[20];
	int ansn;
	while (scanf("%s %s", &str, &num) != EOF) {
		tmp = 1; ansn = 0;
		if (strcmp(str, "B") == 0) {
			for (i = strlen(num) - 1; i >= 0; i--) {
				ansn += tmp * (num[i] - '0');
				tmp = tmp * 2;
			}
			printf("%d\n", ansn);
		}
		if (strcmp(str, "D") == 0) {
			for (i = 0; i <= strlen(num) - 1; i++) {
				ansn =ansn*10+ (num[i] - '0');
			}
			//printf("%d\n", ansn);
			anss[8] = '\0';
			i = 7;
			while (i >= 0) {
				if(ansn>0) {
					anss[i] = (ansn % 2)+'0';
					ansn = ansn / 2;
				}
				else { anss[i] = '0'; }
				i--;
			}
			printf("%s\n", anss);
		}
	}
* long factorial(int n) {
	long ans = 1;
	int i;
	for (i = 1; i <= n; i++) { ans = ans * i; }
	return ans;
}
long c(long a, long b) {
	long ans;
	ans = factorial(b) / factorial(a) / factorial(b - a);
	return ans;
}
double rate(long a, long b) {
	double ans = (double)c(a,b);
	for (int i = 0; i < b; i++) {
		ans = ans * 0.5;
	}
	return ans;
}
int main(){
	int n,i, s[100], wish;
	double ans,cnt;
	while (scanf("%d", &n) != EOF) {
		ans = 0; cnt = 0;
		for (i = 0; i <= n; i++) {
			scanf("%d", &s[i]);
		}
		scanf("%d", &wish);
		for (i = 0; i <= n; i++) {
			if (wish == s[i]) { ans = ans + rate(i, n); }
			//cnt=cnt + rate(i, n);
		}
		printf("%lf\n", ans);
	}
	return 0;
}
* double r, v1, v2;
	while (scanf("%lf %lf %lf", &r, &v1, &v2) != EOF) {
		if (pi * r / v2 > r * (v2 - v1) / v2 / v1) { printf("Yes\n"); }
		else { printf("No\n"); }


	}
* int n,f,i;
	double x[100], y[100],k[100];
	scanf("%d", &n);
	while (n != 0) {
		i = 0; f = 0;
		scanf("%d %d", &x[i], &y[i]);
		for (i = 1; i < n; i++) {
			scanf("%d %d", &x[i], &y[i]);
			if(x[i]!=x[i-1]) {
				k[i] = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
			}
			else {
				k[i] = ((y[i] - y[i - 1]) / (y[i] - y[i - 1])) * 30000.0;
			}
			//printf("%lf\n", k[i]);
		}
		if (x[0] != x[i - 1]) {
			k[0] = (y[0] - y[i - 1]) / (x[0] - x[i - 1]);
		}
		else {
			k[0] = ((y[0] - y[i - 1]) / (y[0] - y[i - 1])) * 30000.0;
		}
		//printf("%lf\n", k[0]);
		for (i = 1; i < n; i++) {
			if (k[i] < k[i - 1]) {
				f++;
				//printf("++\n");
			}
			//else { printf("--\n"); }
		}
		if (k[0] < k[i - 1]) {
			f++;
			//printf("++\n");
		}
		//else { printf("--\n"); }
		if (f > 2) { printf("concave\n"); }
		else { printf("convex\n"); }
		scanf("%d", &n);
	}
* //char d[] = "零一二三四五六七八九";
char d[11][20] = { "零","一","二","三","四","五","六","七","八","九" };
char ws[5][20] = { "个","十","百","千" };
* 	int len, i, j, flag;
	int a[50];
	char s[50];
	while (scanf("%s", s) != EOF){
		len = strlen(s);
		for (i = 0; i < len; i++){ //把数字存到a[0]~a[len-1]里
			a[i] = s[i] - '0';
		}
		if (len == 2 && a[0] == 1){ //单独判断10~19
			printf("十");
			if (a[1] != 0)   //末位不为0的时候
				printf("%s", d[a[1]]);
			printf("\n");
			continue;
		}
		if (len == 1 && a[0] == 0) {//单独判断只有0的情况
			printf("零\n");
			continue;
		}
		for (i = 0; i < len; i++){
			if (a[i] == 0){  //遇到零的情况
				flag = 0;
				for (j = len - 1; j > i; j--){//后面有非零数就可以输出0
					if (a[j] != 0){
						flag = 1;
						break;
					}
				}
				if (!flag){
					continue;
				}
				if (a[i - 1] == 0){  //判断连续0

					continue;
				}
			}
			printf("%s", d[a[i]]);
			if (i != len - 1 && a[i] != 0){
				printf("%s", ws[(len - i - 1)]);
			}
		}
		printf("\n");
	}
	return 0;
int isprime(int a) {//really fixed
	int i, m;
	int flag;
	i = a;
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <= sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
int main() {
	int m, n, i;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n-2; i++) {
		if (isprime(i) == 1 && isprime(i + 2) == 1) {
			printf("%d %d\n", i, i + 2);
		}
	}
}
int n;
	scanf("%d", &n);
	int sum = 0, i = 2;
	while (1){
		if (i <= n){
			i = i * 2;
		}
		else{
			i = ((i - n) * 2) - 1;
		}
		sum++;
		if (i == 2){
			break;
		}
	}
	printf("经%d次洗牌回到初始状态\n", sum);
	return 0;
int cin;
	int a[5],i;
	scanf("%d", &cin);
	for (i = 0; i < 4; i++) {
		a[i] = cin % 10;
		cin=cin / 10;
		a[i] = (a[i] + 5) % 10;
		printf("%d", a[i]);
	}
	printf("\n");

* 	double x1, y1, x2, y2,k1,b1,k2,b2,d1,d2;
	int s,inf1, inf2;
	while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF) {
		inf1 = 0; inf2 = 0;
		if(x1!=x2) {
			k1 = (y2 - y1) / (x2 - x1);
			b1 = y1 - k1 * x1;
		}
		else { inf1 = 1; d1 = x1; k1 = 32767; b1 = 32767; }
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		if(x1 != x2) {
			k2 = (y2 - y1) / (x2 - x1);
			b2 = y1 - k2 * x1;
		}
		else { inf2 = 1; d2 = x1; k2 = 32767; b2 = 32767; }
		if ((inf1 == inf2 && inf1== 1 &&d1!=d2) || (k1 == k2 && b1 != b2)) {
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
* double a[1000], b[1000];
void bubble(int n) {
	int i, k;
	double c;
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (a[k] > a[k + 1]) {
				c = a[k];
				a[k] = a[k + 1];
				a[k + 1] = c;
				c = b[k];
				b[k] = b[k + 1];
				b[k + 1] = c;
			}
		}
	}
}
int main() {
	int i,  k;
	double n, ans;
	char str[100];
	scanf("%lf %d", &n, &k);
	while (n != 0 || k != 0) {
		for (i = 0; i < k; i++) {
			scanf("%s %lf %lf", &str, &a[i], &b[i]);
		}
		bubble(k);
		ans = 0; i = 0;
		while (n != 0 && i < k) {
			if (b[i] * a[i] <= n) { n -= b[i] * a[i]; ans += b[i]; }
			else { ans += (double)n / a[i]; n = 0; }
			i++;
		}
		printf("%.0lf\n", ans);
		scanf("%lf %d", &n, &k);
	}
	return 0;
}
* int isprime(int a) {//really fixed
	int i, m;
	int flag;
	i = a;
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <= sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
int main() {
	int a[110][110];
	int i,n,m,k, cnt;
	for (i = 0; i < 110;i++) {
		for (m = 0; m < 110; m++) {
			a[i][m] = 0;
		}
	}
	while (scanf("%d", &n) != EOF) {
		i = 2; cnt = 0;
		while (i <= n) {
			m = i;
			if (a[i][2] == 0) {
				k = 2;
				while(m>1){
					if (isprime(k) == 1) {
						while (m % k == 0) {
							m = m / k;
							a[i][k]++;
						}
					}
					k++;
				}
				for (m = 2; m < 110; m++) {
					a[i][m] += a[i - 1][m];
				}
			}
			i++;
		}
		printf("%d!=",n);
		for (i = 2; i < 110; i++) {
			if (a[n][i] != 0) { printf(" %d", a[n][i]); }
		}
		printf("\n");
	}

	return 0;
}
* int bubadd(int aa) {
	int i, m; int c;
	int a[100],n,ans;
	i = 0;
	while(aa>0){
		a[i] = aa % 10;
		aa = aa / 10;
		i++;
	}
	n = i;
	for (i = n - 2; i >= 0; i--) {
		for (m = 0; m <= i; m++) {
			if (a[m] < a[m + 1]) {
				c = a[m];
				a[m] = a[m + 1];
				a[m + 1] = c;
			}
		}
	}
	ans = 0;
	for (i = 0; i < n; i++) {
		ans = ans * 10 + a[i];
	}
	return ans;
}
int tran(int a) {
	int ans=0;
	while (a > 0) {
		ans = ans * 10 + a % 10;
		a = a / 10;
	}
	return ans;
}
int main() {
	int a;
	scanf("%d", &a);
	while (a != 6174) {
		printf("%d->", a);
		a = bubadd(a);
		a = a - tran(a);
		//printf("%d->", a);
	}
	printf("6174->6174\n");
	return 0;
}
* int a[100];
void bubbled(int n) {
	int i, k; int c;
	for (i = n - 3; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (a[k] > a[k + 2]) {
				c = a[k];
				a[k] = a[k + 2];
				a[k + 2] = c;
			}
		}
	}
}
int main() {
	int i,cnt=0;
	scanf("%d", &a[cnt]);
	while (a[cnt] != 0) {
		cnt++;
		scanf("%d", &a[cnt]);
	}
	bubbled(cnt);
	for (i = 0; i < cnt-1; i++) { printf("%d ", a[i]); }
	printf("%d\n", a[i]);
}
* int main() {
	char a[100], b[100];
	scanf("%s %s", &a, &b);
	while (strcmp(a,"0")!=0||strcmp(b,"0")!=0) {
		if ((int)(a[strlen(a) - 1] + b[strlen(b) - 1]) % 2 == 0) {
			printf("Yes\n");
		}
		else { printf("No\n"); }
		scanf("%s %s", &a, &b);
	}

	return 0;
}
* int main() {
	int a[60], n;
	int i, tmp, max, tmpa, tmpb, maxa, maxb;
	scanf("%d", &n);
	max = 1; tmp = 1;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i == 0) { tmpa = 0; }
		if (i > 0) {
			if (a[i] == a[i - 1]) {
				tmpb = i;
				tmp++;
				if (tmp > max) {
					max = tmp;
					maxa = tmpa;
					maxb = tmpb;
				}
			}
			else {
				tmp = 1;
				tmpa = i;
			}
		}
	}
	if(max>1){
		printf("The longest equal number list is from %d to %d.", maxa, maxb);
	}
	else{
		printf("No equal number list.");
	}
	return 0;
}
* int maxi(int a, int b) {
	if (a > b) { return a; }
	else { return b; }
}
int isnum(char ch) {
	int a = 0;
	if (ch >= '0' && ch <= '9') { a = 1; }
	return a;
}
int main() {
	int m, k, i;
	char a[10000], b[10000], ans[10000];
	int tmp, s, up, t1, t2, t3;
	//scanf("%d", &m);
	while(scanf("%s %s", &a, &b)!=EOF) {
		t1 = strlen(a) - 1;
		t2 = strlen(b) - 1;
		t3 = maxi(t1, t2);
		ans[t3 + 1] = '\0';
		//ans[0] = '0';
		up = 0;
		while (t1 >= 0 || t2 >= 0) {
			if (t1 < 0) { t1 = 0; a[t1] = '0'; }
			if (t2 < 0) { t2 = 0; b[t2] = '0'; }
			ans[t3] = a[t1] + b[t2] + up - '0';
			up = 0;
			if (isnum(ans[t3]) == 0) { up = 1; ans[t3] -= 10; }
			t1--; t2--; t3--;
		}

		if (up == 1) { printf("1"); }
		printf("%s\n", ans);
	}
	return 0;
}
int main() {
	char s[7];
	int i,f;
	while (gets(s) != NULL) {
		f = 0;
		if (s[5] >= '4') { f = 1; }
		for (i = 4; i >= 2; i--) {
			s[i] = f + s[i];
			if (s[i] >= '7') { s[i] = s[i] - 7; f = 1; }
			else { f = 0; }
		}
		if (f == 1) { s[0]++; }
		for (i = 0; i < 5; i++) {
			printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}
* int main() {
	int a, b;
	long cnt = 0;
	long w[100][100];
	int i, k;
	for (i = 1; i < 100; i++) {
		w[i][0] = 1;
		for (k = 1; k < i; k++) {
			w[i][k] = w[i][k - 1] + w[i - 1][k];
		}
		w[i][k] = w[i][k - 1];
	}
	scanf("%d,%d", &a, &b);
	printf("%ld\n",w[a][b]);
}
* void move(char x, char y) {
	printf("%c>%c\n", x, y);
}
void hanno(int n, char a, char b, char c) {
	if (n == 1) { move(a, c); }
	else {
		hanno(n - 1, a, c, b);
		move(a, c);
		hanno(n - 1, b, a, c);
	}
}
int main() {
	int a, b;
	scanf("%d", &a);
	while (a != 0) {
		hanno(a, 'A', 'B', 'C');
		b = pow(2, a) - 1;
		printf("%d\n", b);
		scanf("%d", &a);
	}

}
* int c(int n, int m) {
	if (n > (m - n)) { n = m - n; }
	if (n == 0) { return 1; }
	if (n == 1) { return m; }
	if (n > 1) { return (c(n - 1, m - 1) + c(n, m - 1)); }
}
int main() {
	int m, n,ans;
	scanf("%d %d", &m, &n);
	ans = c(n, m);
	printf("%d\n", ans);
}
* 	int sum, a, b, ans, tmp,cnt=0,i;
	int e[65];
	tmp = 0;
	for (a = 1; a <= 62; a++) {
		if (tmp == cnt) { e[a] = 1; cnt++; tmp = 0; }
		else { e[a] = 0; tmp++; }
	}
	scanf("%d/%d", &a, &b);
	while (a + b != 0) {
		sum = 0;
		i = 0;
		if (a == 8) { i = 31; }
		i = i + b;
		while (i <= 62) {
			sum = sum + e[i];
			i++;
		}
		printf("%d\n",sum);
		scanf("%d/%d", &a, &b);
	}
	return 0;
int main() {
	long long a[50],i,m;
	a[0] = 1; a[1] = 1;
	for (i = 2; i < 50; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	while (scanf("%lld", &m) != EOF) {
		printf("%lld\n", a[m - 1]);
	}
	return 0;
}

* int zh(int m, int n)
{
	if (n > m - n)
	{
		n = m - n;
	}
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return m;
	}
	if (n > 1)
	{
		return zh(m - 1, n - 1) + zh(m - 1, n);
	}

}
int main()
{
	int m, n, ans;
	scanf("%d%d", &m, &n);

	ans = zh(m, n);
	printf("%d\n", ans);
	return 0;
}
* long factorial(int n) {
	long ans=1;
	int i;
	for (i = 1; i <= n; i++) {ans = ans * i;}
	return ans;
}
int main() {
	long m, a, b, ans;
	while (scanf("%ld", &m) != EOF) {
		ans = 0;
		for (a = 0; a <= (m - 1) / 2; a++) {
			b = (m-1)-a * 2;
			ans = ans + factorial(a + b) / (factorial(a) * factorial(b));
		}
		printf("%ld\n", ans);
	}
	return 0;
}
* int maxi(int a, int b) {
	if (a > b) { return a; }
	else { return b; }
}
int isnum(char ch) {
	int a = 0;
	if (ch >= '0' && ch <= '9' ) { a = 1; }
	return a;
}
int main() {
	int m, k, i;
	char a[10000], b[10000],ans[10000];
	int tmp, s, up,t1,t2,t3;
	scanf("%d", &m);
	for (k = 0; k < m; k++) {
		scanf("%s %s", &a, &b);
		t1 = strlen(a) - 1;
		t2 = strlen(b) - 1;
		t3 = maxi(t1, t2);
		ans[t3 + 1] = '\0';
		//ans[0] = '0';
		up = 0;
		while (t1 >= 0 || t2 >= 0) {
			if (t1 < 0) { t1 = 0; a[t1] = '0'; }
			if (t2 < 0) { t2 = 0; b[t2] = '0'; }
			ans[t3] = a[t1] + b[t2] + up-'0';
			up = 0;
			if (isnum(ans[t3]) == 0) { up = 1; ans[t3] -= 10; }
			t1--; t2--; t3--;
		}

		if (up == 1) {printf("1");}
		printf("%s\n", ans);
	}
	return 0;
}
* ////////////////////////////////////////////////////
* int m,k, i;
	char a[10000], b[10000];
	long c[10000], d[10000], ans[10000], tmp,s,up;
	scanf("%d", &m);
	for (k = 0; k < m; k++) {
		for (k = 0; k < 10000; k++) {
			c[k] = 0;
			d[k] = 0;
		}
		scanf("%s %s", &a, &b);
		tmp = 0;s = 0;
		for (i = strlen(a) - 1; i >= 0; i--) {
			if (isnum(a[i]) == 1) { tmp = tmp * 10 + (int)(a[i] - '0'); }
			else { break; }
			if (tmp >= 10000) { c[s] = tmp; s++; tmp = 0; }
		}
		c[s] = tmp;

		tmp = 0; s = 0;
		for (i = strlen(b) - 1; i >= 0; i--) {
			if (isnum(a[i]) == 1) { tmp = tmp * 10 + (int)(b[i] - '0'); }
			else { break; }
			if (tmp >= 10000) { d[s] = tmp; s++; tmp = 0; }
		}
		d[s] = tmp;

		tmp = 0; s = 0; up = 0;
		while (c[s]!=0||d[s]!=0) {
			tmp = c[s] + d[s] + up;
			up = tmp / 10000;
			tmp = tmp % 10000;
			ans[s] = tmp;
			//printf("%ld\n", ans[s]);
			//getch();
			s++;
		}
		s--;
		while (s>= 0) {
			ans[s] = reverse(ans[s]);
			printf("%ld", ans[s]);
			s--;
		}
		printf("\n");
	}


* ////////////////////////////FAIL////////////////////
* #define n 5
int main() {
	int a[4], i1, i2, i3, i4, i5,tmp;
	int b[30000];
	for (i1 = 0; i1 < 30000; i1++) {
		b[i1] = 0;
	}
	for (i1 = 0; i1 < 4; i1++) {
		scanf("%d", &a[i1]);
	}
	for (i1 = n ; i1 >= 0; i1--) {
		for (i2 = n - i1; i2 >= 0; i2--) {
			for (i3 = n - (i1 + i2); i3 >= 0; i3--) {
				for(i4 = n - (i1 + i2 + i3);i4>=0;i4--){
					tmp = a[0] * i1 + a[1] * i2 + a[2] * i3 + a[3] * i4;
					//printf("%d %d %d %d %d\n", i1,i2,i3,i4,tmp);
					b[tmp] = 1;
				}
			}
		}
	}
	i1 = 1;
	while (b[i1] == 1) {
		i1++;
	}
	printf("%d.", i1 - 1);

	return 0;
}
* int isword(char ch) {
	int a=0;
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') { a = 1; }
	return a;
}
int main() {
	char a[1000], ans[100],tmp[100];
	int cnt = 0, min =32767,i;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (isword(a[i]) == 1) {
			tmp[cnt] = a[i];
			cnt++;
			if (i == strlen(a) - 1) {
				tmp[cnt] = '\0';
				if (cnt < min) { strcpy( ans,tmp); min= cnt; }
				cnt = 0;
			}
		}
		if (isword(a[i]) == 0&&cnt!=0) {
			tmp[cnt] = '\0';
			if (cnt < min) { strcpy(ans,tmp); min = cnt; }
			cnt=0;
		}
	}
	printf("%s\n", ans);
	return 0;
}
* int test(int i) {
	int a, b, c, d;
	b = 0;
	while (i > 0) {
		b = b * 10 + i % 10;
		i = i / 10;
	}
	return b;
}
int isprime(int a) {//really fixed
	int i, m;
	int flag;
	i = a;
	//scanf_s("%d", &n);
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <= sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	int m, k,cnt,a,b;
	cnt = 0;
	scanf("%d %d", &a, &b);
	for(m=a;m<b;m++){
		if (isprime(m) == 1 && isprime(test(m)) == 1) {
			printf("%5d", m);
			cnt++;
		}
		if (cnt == 10) { printf("\n"); cnt = 0; }
	}

	return 0;
}
* int minx(int a, int b) {
	int c = 1, i;
	for (i = 2; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			c = i;
		}
	}
	return(c);
}
int main(){
	int a, b, c, d, up, down,m;
	while (scanf("%d/%d * %d/%d", &a, &b, &c, &d)!= EOF){
		//printf("%d %d %d %d", a, b, c, d);
		up = a * c;
		down = b * d;
		m = minx(up, down);
		up = up / m;
		down = down / m;
		if (down != 1) {
			printf("%d/%d * %d/%d = %d/%d\n", a, b, c, d, up, down);
		}
		if (down == 1) {
			printf("%d/%d * %d/%d = %d\n", a, b, c, d, up);
		}
	}
	return 0;
}
* int factorsum(int a) {
	int i, sum;
	sum = 0;
	for (i = 1; i < a; i++) {
		if (a % i == 0) { sum += i; }
	}
	return sum;
}
int main(){
	int a, b,j,cnt;
	int p[100];
	cnt = 0;
	scanf("%d %d", &a, &b);
	for (j = a; j <= b; j++) {
		if (factorsum(j) == j) { p[cnt] = j; cnt++; }
	}
	for (j = 0; j < cnt-1; j++) { printf("%d ", p[j]); }
	printf("%d\n", p[j]);
	return 0;
}
* char s[1000];
	int len, i;
	while (gets(s) != NULL){
		len = strlen(s);
		for (i = 0; i < len - 1; i++){
			if (s[i] == 'w' && s[i + 1] == 'e'){
				printf("you");
				i++;
			}
			else
				printf("%c", s[i]);
		}
		if(i==len-1){
		printf("%c\n", s[i]);
		}
		else {
			printf("\n");
		}
	}
* int Judge(char ch){
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		return 1;
	return 0;
}
int main(){
	int l1, l2, cnt1, cnt2, p1, p2;
	int i, j, len, flag;
	char s1[10000], s2[10000];
	char tmp[50];
	char t1[100][50], t2[100][50];
	while(gets(s1)!=NULL) {
		gets(s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		cnt1 = cnt2 = 0;
		p1 = p2 = 0;
		len = 0;
		flag = 0;
		for (i = 0; i < l1; i++) {
			if (Judge(s1[i])) {
				if (s1[i] >= 'A' && s1[i] <= 'Z')
					s1[i] = s1[i] + 32;
				t1[cnt1][p1++] = s1[i];
				if (i == l1 - 1) {
					t1[cnt1][p1] = '\0';
					cnt1++;
					p1 = 0;
				}
			}
			else if (p1 != 0)
			{
				t1[cnt1][p1] = '\0';
				cnt1++;
				p1 = 0;
			}
		}
		for (i = 0; i < l2; i++)
		{
			if (Judge(s2[i])) {
				if (s2[i] >= 'A' && s2[i] <= 'Z')
					s2[i] = s2[i] + 32;
				t2[cnt2][p2++] = s2[i];
				if (i == l2 - 1) {
					t2[cnt2][p2] = '\0';
					cnt2++;
					p2 = 0;
				}
			}
			else if (p2 != 0) {
				t2[cnt2][p2] = '\0';
				cnt2++;
				p2 = 0;
			}

		}
		for (i = 0; i < cnt1; i++)
			for (j = 0; j < cnt2; j++)
			{
				if (strcmp(t1[i], t2[j]) == 0)
				{
					flag = 1;
					if (strlen(t1[i]) > len)
					{
						strcpy(tmp, t1[i]);
						len = strlen(t1[i]);
					}
				}
			}
		if (flag)
			printf("%s\n", tmp);
		else
			printf("No common word!\n");
	}
	return 0;
}
* int Judge(char ch)//判断是不是字母
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		return 1;
	return 0;
}
int main()
{
	int l1, l2, cnt1, cnt2, p1, p2;
	int i, j, len, flag;
	char s1[10000], s2[10000];//存储原始两字符串
	char tmp[500];//存储最长公共单词
	char t1[10000][500], t2[10000][500];//存储单词
	while (gets(s1) != NULL)
	{
		gets(s2);
		l1 = strlen(s1);//存储字符串总长度
		l2 = strlen(s2);
		cnt1 = cnt2 = 0;//用cnt进行单词计数
		p1 = p2 = 0;//变量p作为存储单词时的下标
		len = 0;
		flag = 0;
		for (i = 0; i < l1; i++)//从第一个字符串提取单词
		{
			if (Judge(s1[i]))//判断是不是字母
			{
				if (s1[i] >= 'A' && s1[i] <= 'Z')//转小写
					s1[i] = s1[i] + 32;
				t1[cnt1][p1++] = s1[i];//存入字符
			}
			else if (p1 != 0)//防止连续非字母
			{
				t1[cnt1][p1] = '\0';
				cnt1++;
				p1 = 0;
			}
		}
		for (i = 0; i < l2; i++)//从第二个字符串提取单词
		{
			if (Judge(s2[i]))
			{
				if (s2[i] >= 'A' && s2[i] <= 'Z')
					s2[i] = s2[i] + 32;
				t2[cnt2][p2++] = s2[i];
			}
			else if (p2 != 0)
			{
				t2[cnt2][p2] = '\0';
				cnt2++;
				p2 = 0;
			}
		}
		for (i = 0; i < cnt1; i++)//暴力枚举
			for (j = 0; j < cnt2; j++)
			{
				if (strcmp(t1[i], t2[j]) == 0)//存在相等
				{
					flag = 1;//标记存在公共单词
					if (strlen(t1[i]) > len)//比已存的长
					{
						strcpy(tmp, t1[i]);
						len = strlen(t1[i]);
					}
				}
			}
		if (flag)
			printf("%s\n", tmp);
		else
			printf("No common word!\n");
	}
	return 0;
}
* char a[1000];
	int i;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			printf("%c", a[i]);
		}
	}
* ////////////////////////////error
* char ans[1000][16];
void bubble2(int n) {
	int i, m;
	char tmp[100];
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (strcmp(ans[m], ans[m + 1]) > 0) {
				strcpy(tmp, ans[m]);
				strcpy(ans[m], ans[m + 1]);
				strcpy(ans[m + 1], tmp);
			}
		}
	}
}
int main() {
	char a[1000][16];
	char x[1000][16];
	char n[1000][16];
	int cnte, cntn, cnta;
	int q, i, m;
	scanf("%d", &q);
	while (q != 0) {
		cnte = 0; cntn = 0; cnta = 0;
		for (i = 0; i <= q; i++) {
			gets(a[i]);
			if (strcmp(&a[i][strlen(a[i]) - 4], ".exe") == 0 && strlen(a[i]) > 4) {
				a[i][strlen(a[i]) - 4] = '\0';
				strcpy(x[cnte], a[i]);
				cnte += 1;
			}
			else {
				strcpy(n[cntn], a[i]);
				cntn += 1;
			}
		}
		//printf("done1\n");
		for (i = 0; i < cnte; i++) {
			for (m = 0; m < cntn; m++) {
				if (strcmp(x[i], n[m]) == 0) {
					strcpy(ans[cnta], x[i]);
					cnta++;
				}
			}
		}
		//printf("done2\n");
		bubble2(cnta);
		//printf("done3\n");
		for (m = 0; m < cnta; m++) {
			printf("%s.exe\n", ans[m]);
		}
		scanf("%d", &q);
	}


	return 0;
}
* //////////////////////////////////////////////
* int main() {

	long a, b, n, i, k, ans, f;
	while (scanf("%ld %ld", &a, &b) != EOF) {
		f = 1; ans = 0;
		for (k = 1; k <= a / 2; k++) {
			if (a % k == 0) { ans = ans + k; }
		}
		if (ans != b) { f = 0; }
		ans = 0;
		for (k = 1; k <= b / 2; k++) {
			if (b % k == 0) { ans = ans + k; }
		}
		if (ans != a) { f = 0; }
		if (f) { printf("Yes\n"); }
		else { printf("No\n"); }
	}

	return 0;
}

* ////////////////error///////////////////////////////
* char ans[1000][16];
void bubble2(int n) {
	int i, m;
	char tmp[100];
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (strcmp(ans[m], ans[m + 1]) < 0) {
				strcpy(tmp, ans[m]);
				strcpy(ans[m], ans[m + 1]);
				strcpy(ans[m + 1], tmp);
			}
		}
	}
}
int main() {
	char a[1000][16];
	char x[1000][16];
	char n[1000][16];
	int cnte, cntn,cnta;
	int n, i,m;
	scanf("%d", &n);
	while (n != 0) {
		cnte = 0; cntn = 0; cnta = 0;
		for (i = 0; i < n; i++) {
			gets(a[i]);
			if (strcmp(&a[i][strlen(a[i]) - 4], ".exe") == 0){
				a[i][strlen(a[i]) - 4] = '\0';
				strcpy(x[cnte], a[i]);
				cnte += 1;
			}
			else {
				strcpy(n[cntn], a[i]);
				cntn += 1;
			}
		}
		for (i = 0; i < cnte; i++) {
			for (m = 0; m < cntn; m++) {
				if (strcmp(x[i],n[m]) == 0) {
					strcpy( ans[cnta], x[i]);
					cnta++;
				}
			}
		}
		bubble2(cnta);
		for (m = 0; m < cnta; m++) {
			printf("%s.exe\n", ans[m]);
		}
		scanf("%d", &n);
	}


	return 0;
}
//////////////////////////////////////////////
* int main() {
	char a[100];
	int asc[256];
	int i;
	for (i = 0; i < 256; i++) {
		asc[i] = 0;
	}
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (asc[a[i]] == 0) {
			printf("%c", a[i]);
			asc[a[i]] = 1;
		}
	}
	return 0;
}

* int main() {
	char a[100],tmp='\0';
	int i;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (tmp == '\0') {
			if (a[i] == 'i' || a[i] == 'I') {
				tmp = a[i];
			}
			else { printf("%c", a[i]); }
		}
		else {
			if (a[i] == 's' || a[i] == 'S') {
			}
			else {
				printf("%c",tmp);
				printf("%c", a[i]);
			}
			tmp = '\0';
		}


	}
	return 0;
}
* char a[100][100];
void bubble2(int n) {
	int i, m;
	char tmp[100];
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (strcmp(a[m], a[m + 1]) < 0) {
				strcpy(tmp, a[m]);
				strcpy(a[m], a[m + 1]);
				strcpy(a[m + 1], tmp);
			}
		}
	}
	strcpy(tmp, a[0]);
	strcpy(a[0], a[4]);
	strcpy(a[4], tmp);
}
int main() {
	int n = 5;
	int i;
	for (i = 0; i < n; i++) {
		gets(a[i]);
	}
	bubble2(n);
	for (i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}
	return 0;
}

* long n;
int r;
char ct[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };//change in string
char ans[100];
char ans2[100];
int tmp;
int i, flag;
while (scanf("%ld %d", &n, &r) != EOF) {
	i = 0; flag = 0;
	if (n < 0) {
		n = -n;
		flag = 1;
	}
	while (n > 0) {
		tmp = n % r;
		n = n / r;
		ans[i] = ct[tmp];
		i++;
	}
	if (flag == 1) {
		ans[i] = '-';
		ans[i + 1] = '\0';
	}
	else {
		ans[i] = '\0';
	}
	//strrev(ans);
	flag = 0;
	for (i = strlen(ans) - 1; i >= 0; i--) {
		ans2[flag] = ans[i];
		flag++;
	}
	ans2[flag] = '\0';
	printf("%s\n", ans2);
}
*
* int main() {
	int a[100], n, m[100];
	long long int s2 = 1;
	while (scanf("%d", &n) != EOF) {


		int i = 0, x = 0, s1 = 0, s3 = 0;
		s2 = 1;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] < 0) {
				s1++;//统计负数个数
			}
			if (a[i] != 0) {
				s2 = s2 * a[i];//除零以外的数相乘
			}
			if (a[i] == 0) {
				s3++;
			}


		}
		if (s3 == n) {
			printf("0\n");
		}
		else if (s1 % 2 != 0) {
			for (i = 0; i < n; i++) {
				if (a[i] < 0) {
					m[x++] = a[i];
				}
			}

			int min = m[0];
			for (x = 0; x < s1; x++) {
				if (m[x] > min) {
					min = m[x];
				}
			}

			s2 = s2 / min;
			printf("%lld\n", s2);
			break;


		}
		else {
			printf("%lld\n", s2);
		}




	}
	return 0;
}

* 	int n, i,m;
	scanf("%d", &n);
	printf("%d=", n);
	m = n;
	for (i = 2; i <= n; i++) {
		while (n % i == 0) {
			if (i != n) {
				printf("%d*", i);
				n = n / i;
			}
			if (i == n) {
				printf("%d", i);
				n = n / i;
				i = n;
				break;
			}
		}
	}
* float a[6][6];
	int i, m,n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (m = 0; m < n; m++) {
			scanf("%f", &a[i][m]);
		}
	}
	for (i = 0; i < n; i++) {
		for (m = 0; m < n-1; m++) {
			printf("%.2f ", a[i][m]/a[i][i]);
		}
		printf("%.2f\n", a[i][m] / a[i][i]);
	}

* int a[1005];
	int n, s, m,i, cnt, num;
	scanf("%d %d %d", &n, &s, &m);
	num = n;
	for (i = 0; i <= n; i++) {
		a[i] = 1;
	}
	i = s; cnt = 0;
	while (num > 1) {
		if (a[i] == 1) { cnt++; }
		if (cnt == m) { a[i] = 0; num--; cnt = 0; }
		i++;
		if (i > n) { i = 1; }
	}
	for (i = 1; i <= n; i++) {
		if (a[i] == 1) { printf("%d", i); }
	}

* int n,i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		bubble2(n);
		for (i = 0; i < n-1; i++) {
			printf("%d ", a[i]);
		}
		printf("%d\n", a[i]);
	}
* int a[1000];

* void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void bubble2(int n) {
	int i, m;
	for (i = 0; i < n - 1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (a[m]>0 && a[m + 1]<0) { swap(&a[m + 1], &a[m]); }
		}
	}
}
* double bottom = 0.0;
	double top = 1.0;
	double x, err;
	x = (bottom + top) / 2.0;
	scanf("%lf %d %lf", &a, &b, &c);
	err = test(x);
	//printf("%llf\n", err);
	while (err > 0.0001 || err < -0.0001) {
		if (err > 0) { top = x; }
		if (err < 0) { bottom = x; }
		x = (bottom + top) / 2.0;
		err = test(x);
		//printf("%llf\n", err);
	}
	x = x * 100.0;
	printf("%.3lf%%\n", x);
* double a, c;
int b;

double test(double x) {
	int i;
	double sum;
	sum = a;
	for (i = 0; i < b; i++) {
		sum = sum*( x +1.0) - c;
	}
	return sum;
}

* 	long a, b;
	long long ans = 0;
	long i;
	//primecheck();
	//for (i = 0; i < cnt; i++) {printf("%d\n", prime[i]);}
	while (scanf("%ld %ld", &a, &b) != EOF) {
		if (a > b) { swap(&a, &b); }
		ans = 0;
		for (i = a + 1; i < b; i++) {
			if (isprime(i)) {
				ans = ans + i;
				//printf("%d\n", i);
			}
		}
		printf("%lld\n", ans);
	}
* void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int isprime(long a) {//really fixed
	int i, m;
	int flag;
	i = a;
	//scanf_s("%d", &n);
	flag = 1;
	if (i == 1) { return 0; }
	for (m = 2; m <=sqrt(i); m++) {
		if (i % m == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

* long prime[30000];
int cnt = 0;
* void primecheck() {//fast
	long i, m;
	int flag;
	//scanf_s("%d", &n);
	prime[0]=2;
	cnt++;
	for(i=3;i< 65536;i=i+2){
		flag = 1;
		for (m =0; m <cnt; m++) {
			if (i % prime[m] == 0) {
				flag = 0;
				break;
			}
		}
		for (m = prime[cnt-1]; m <= sqrt(i); m++) {
			if (i % m == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			prime[cnt] = i;
			cnt++;
		}
	}
}
* long isprime2(long a) {//fast//might need bisection
	long i, m;
	int flag;
	i = a;
	//scanf_s("%d", &n);
	flag = 0;
	for (m = 0; m <cnt; m++) {
		if (prime[m] > i ) {
			break;
		}
		if (i == prime[m]) {
			flag = 1;
			break;
		}
	}
	return flag;
}
* 	int n,i;
	long long max,tmp;
	while(scanf("%d", &n)!=EOF){
		max = 1; tmp = 0;
		for (i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		bubble(n);
		for (i = 0; i < n; i++) {
			//printf("%d ", a[i]);
			if (a[i] > 0) {
				max = max * a[i];
				continue;
			}
			if (a[i] < 0 && tmp == 0) {
				tmp = a[i];
				continue;
			}
			if (a[i] < 0 && tmp != 0) {
				max = max * a[i];
				max = max * tmp;
				tmp = 0;
				continue;
			}
		}
		printf("%lld\n", max);
	}
* int a[1000];
void swap(int *a, int *b) {66
	*a = *b;
	*b = c;
}
void bubble(int n) {
	int i, m;
	for (i = 0; i < n-1; i++) {
		for (m = 0; m < n - 1; m++) {
			if (a[m] > a[m + 1]) { swap(&a[m + 1], &a[m]); }
		}
	}
}
///////////////////////////////////////////////////
////////////////////2048//////////////////////////
///////////////////////////////////////////////////
 #include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#define  n 4	//size of the map
long num, a[n][n],err,score;
void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int rnd(unsigned int a) {
	int ans = a/2;
	float b=rand();
	ans = (int)a * (b / 32767.0);
	return ans;
}
void display() {
	int i, m;
	for (i = 0; i < n; i++) {//output
		for (m = 0; m < n; m++) {
			if (a[i][m] == 0) { printf("     "); }
			else { printf("%5d", a[i][m]); }
		}
		printf("\n\n");
	}
	printf("\n\n");
}
void merge(char mode) {
	int i, m,k,tmp;
	char in;
	if (mode == '4' || mode == 'a') {
		for (i = 0; i < n; i++) {
			m = 1;
			while (m < n&&m>=1) {
				while (a[i][m - 1] == 0 && a[i][m] != 0&&m>0) {
					swap(&a[i][m - 1], &a[i][m]);
					//display();
					m--;
				}
				m++;
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			for (m = 0; m < n-1; m++) {
				if (a[i][m + 1] == a[i][m]&& a[i][m]!=0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i][m+1] = 0;
					num++;
					m++;
				}
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			m = 1;
			while (m < n && m >= 1) {
				while (a[i][m - 1] == 0 && a[i][m] != 0 && m > 0) {
					swap(&a[i][m - 1], &a[i][m]);
					m--;
				}
				m++;
			}
		}
	}
	else if (mode == '8'|| mode == 'w') {
		for (m = 0; m < n; m++) {
			i = 1;
			while (i < n && i >= 1) {
				while (a[i-1][m] == 0 && a[i][m] != 0 && i > 0) {
					swap(&a[i-1][m], &a[i][m]);
					//display();
					i--;
				}
				i++;
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			for (i = 0; i < n - 1; i++) {
				if (a[i+1][m] == a[i][m] && a[i][m] != 0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i+1][m] = 0;
					num++;
					i++;
				}
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			i = 1;
			while (i < n && i >= 1) {
				while (a[i - 1][m] == 0 && a[i][m] != 0 && i > 0) {
					swap(&a[i - 1][m], &a[i][m]);
					//display();
					i--;
				}
				i++;
			}
		}
	}
	else if (mode == '6' || mode == 'd') {
		for (i = 0; i < n; i++) {
			m = n-2;
			while (m < n-1 && m >= 0) {
				while (a[i][m + 1] == 0 && a[i][m] != 0 && m < n-1) {
					swap(&a[i][m + 1], &a[i][m]);
					//display();
					m++;
				}
				m--;
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			for (m = n-1; m >0; m--) {
				if (a[i][m - 1] == a[i][m] && a[i][m] != 0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i][m - 1] = 0;
					num++;
					m--;
				}
			}
		}
		//display();
		for (i = 0; i < n; i++) {
			m = n - 2;
			while (m < n-1 && m >= 0) {
				while (a[i][m + 1] == 0 && a[i][m] != 0 && m < n - 1) {
					swap(&a[i][m + 1], &a[i][m]);
					//display();
					m++;
				}
				m--;
			}
		}
	}
	else if (mode == '2' || mode == 's' || mode == '5') {
		for (m = 0; m < n; m++) {
			i = n - 2;
			while (i < n - 1 && i >= 0) {
				while (a[i+1][m] == 0 && a[i][m] != 0 && i < n - 1) {
					swap(&a[i+1][m], &a[i][m]);
					//display();
					i++;
				}
				i--;
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			for (i = n - 1; i > 0; i--) {
				if (a[i-1][m] == a[i][m] && a[i][m] != 0) {
					a[i][m] = a[i][m] * 2;
					score += a[i][m];
					a[i-1][m] = 0;
					num++;
					i--;
				}
			}
		}
		//display();
		for (m = 0; m < n; m++) {
			i = n - 2;
			while (i < n - 1 && i >= 0) {
				while (a[i + 1][m] == 0 && a[i][m] != 0 && i < n - 1) {
					swap(&a[i + 1][m], &a[i][m]);
					//display();
					i++;
				}
				i--;
			}
		}
	}
	else {
	printf("Press'8''6''4''2'to play..\n");
	in = getch();
	merge(in);
	}
}
void initialize() {
	printf("Initializing...\n");
	int i, m;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {//start
		for (m = 0; m < n; m++) {
			a[i][m] = 0;
		}
	}
	num = n * n;
	err = 0;
	score = 0;
	printf("Done!\n");
}
void gameloop() {
	int i, m, k, tmp;
	char in;
	while (err == 0) {
		//check empty boxes
		tmp = rnd(num) + 1;
		for (i = 0; i < n; i++) {//rnd new box
			for (m = 0; m < n; m++) {
				if (a[i][m] == 0) {
					tmp--;
					if (tmp == 0) {
						a[i][m] = 2;
						num--;
						if (num == 0) {
							err = 1;
						}
						break;
					}
				}
			}
			if (tmp == 0) { break; }
		}
		display();
		//scanf("%c\n", &in);
		in = getch();
		merge(in);
	}
}
void end() {
	printf("Gameover...\n\nScore=%ld",score);
	while (1) {
		getch();
	}
}
int main(){
	initialize();
	gameloop();
	end();
}

 /////////////////////////////////////////////////////
int add(int n, int m, int a){
	int i;
	i = m + n + a;
	return i;
}
int tet(int n, int m, int a){
	int i;
	i = m * m + n * n + a * a;
	return i;
}
int sd(int i){
	int t = 0, y = 0;
	int a, b, c, d, e,f,k[1000], m = 0;
	for (a = 1; a < i; a++){
		for (b = a+1; b < i; b++) {
			for (c = b+1; c < i; c++) {
				if (add(a, b, c) == i){
					for (d = a+1; d < i; d++) {
						for (e = d+1; e < i; e++) {
							for (f = e+1; f < i; f++) {
								if (add(d,e,f) == i&& tet(a, b, c)== tet(d, e, f)) {
									printf("(%d,%d,%d):(%d,%d,%d)\n", a,b,c,d,e,f);
								}
							}
						}
					}
				}
			}
		}
	}

}
	int s, m, n;
	scanf("%d", &s);
	sd(s);
	return 0;
int i, a, c = 0, k, m;
	char str[1010];
	gets(str);
	for (i = 0;i<strlen(str); i++) {
		if ((str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')){
			printf("%c",str[i]);
			k = 1;
		}
		else if(k==1) {
			k = 0;
			printf("\n");
		}
	}
void bubble(int n) {
	int i, k; int c;
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (a[k] < a[k + 1]) {
				c = v[k];
				v[k] = v[k + 1];
				v[k + 1] = c;
				c = t[k];
				t[k] = t[k + 1];
				t[k + 1] = c;
			}
		}
	}
}
int a[10][10];
	int i, k, m, max, min, maxp, minp, err;
	int ans[2]={9,9};
	scanf("%d", &m);
	for (i = 0; i <m; i++) {
		for (k = 0; k <m; k++) {
			scanf("%d", &a[i][k]);
		}
	}
	for (i = 0; i < m; i++) {
		max = a[i][0];
		maxp = 0;
		err = 0;
		for (k = 0; k < m; k++) {
			if (a[i][k] > max) {
				max = a[i][k];
				maxp = k;
			}
		}
		for (k = 0; k < m; k++) {
			if (a[i][k] == max&&k!=maxp) {
				err = 1;
			}
		}
		if (err == 1) { continue; }
		min = a[i][maxp];
		minp = 0;
		for (k = 0; k < m; k++) {
			if (a[k][maxp] <= a[i][maxp]&&k!=i) {
				err = 1;
			}
		}
		if (err == 1) { continue; }
		else { printf("%d %d", i, maxp); err = 2; break; }
	}
	if (err != 2) { printf("NO"); }

int x, y, ans1, ans2;
	while(scanf("%d %d", &x, &y)!=EOF){
		ans1 = minx(x, y);
		ans2 = maxx(x, y);
		printf("%d %d", ans1, ans2);
	}

int isprime(int a) {//fixed
	int i, m;
	int flag;
	i = a;
	//scanf_s("%d", &n);
	flag = 1;
	for (m = 2; m <= i / 2; m++) {
		if (i % m == 0) {
			flag = 0;
		}
	}
	return flag;
}
int i,p[100],num,n,a,b,c,cnt;
	num = 0;
	for (i = 3; i <= 200; i++) {
		if (isprime(i)) {
			p[num] = i;
			//printf("%d\n", p[num]);
			num++;
		}
	}
	scanf("%d", &n);
	while (n != 0) {
		cnt = 0;
		for (a = 0; a < num; a++) {
			for (b = 0; b <= a; b++) {
				for (c = 0; c <= b; c++) {
					if (n == p[a] + p[b] + p[c]) {
						cnt++;
						//printf("%d %d %d\n", p[a], p[b], p[c]);
					}
				}
			}
		}
		if (cnt == 0) { printf("Error\n"); }
		else { printf("%d\n", cnt); }
		scanf("%d", &n);
	}

long long reverse(long long i) {
	long long b;
	b = 0;
	while (i > 0) {
		b = b * 10 + i % 10;
		i = i / 10;
	}
	return b;
}
long long change(long n, int m) {
	long long ans = 1;
	while(n>0){
		ans = ans * 10 + n % m;
		n = n / m;
	}
	ans = (reverse(ans) - 1) / 10;
	return ans;
}
int main() {
	int i;
	long a, b;
	while (scanf("%ld", &a) != EOF) {
		for (i = 2; i <= 10; i++) {
			if (reverse(change(a, i)) == change(a, i)) { printf("Yes\n"); break; }// printf("%lld\n", change(a, i));
		}
		if (i == 11) { printf("No\n"); }
	}
	return 0;
}
////////////////////////////////////////////////
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int i;
	scanf("%d", &a[10]);
	for (i = 10; i > 0; i--) {
		if (a[i] < a[i - 1]) { swap(&a[i], &a[i - 1]); }
	}
	for (i = 0; i <=10; i++) {
		printf("%d\n", a[i]);
	}
float score(int n) {
	float tmp, max, min, i, sum;
	min = 10;
	max = 0;
	sum = 0;
	for (i = 0; i < n; i++) {
		scanf("%f", &tmp);
		sum = tmp + sum;
		if (tmp > max) { max = tmp; }
		if (tmp < min) { min = tmp; }
	}
	sum = sum - max - min;
	sum = sum /(n-2.0);
	return sum;
}
	int n, m,i,k,a[50];
	float s[50],c;
	scanf("%d,%d", &n, &m);
	for (i = 0; i < n; i++) {
		s[i] = score(m);
		a[i] = i+1;
	}
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if (s[k] < s[k + 1]) {
				c = s[k];
				s[k] = s[k + 1];
				s[k + 1] = c;
				c = a[k];
				a[k] = a[k + 1];
				a[k + 1] = c;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("第%d名:%d号选手,得分%.2f\n", i + 1, a[i], s[i]);
	}
int test(int i) {
	int b;
	b = 0;
	while (i > 0) {
		b = b * 10 + i % 10;
		i = i / 10;
	}
	return b;
}
int testy(long i) {
	long b;
	b = 0;
	while (i > 0) {
		b = b * 10 + i % 10;
		i = i / 10;
	}
	return b;
}
int m;
	long a, b, c;
	scanf("%d", &m);
	a = m * m;
	b = m * m * m;
	if(m==test(m)&a==testy(a)&&b==testy(b)){
		printf("%d是三重回文数", m);
	}
	else {
		printf("%d不是三重回文数", m);
	}
	char a[100], b[100];
	int i, pos;
	gets(a);
	gets(b);
	scanf("%d", &pos);
	for (i = 0; i < pos; i++) {
		printf("%c", b[i]);
	}
	for (i = 0; i <strlen(a); i++) {
		printf("%c", a[i]);
	}
	for (i = pos; i < strlen(b); i++) {
		printf("%c", b[i]);
	}
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

double m, n,t[30], v[30];

void bubble(int n) {
	int i, k; int c;
	for (i = n - 2; i >= 0; i--) {
		for (k = 0; k <= i; k++) {
			if ((double)v[k]/ (double)t[k] < (double)v[k + 1]/ (double)t[k+1]) {
				c = v[k];
				v[k] = v[k + 1];
				v[k + 1] = c;
				c = t[k];
				t[k] = t[k + 1];
				t[k + 1] = c;
			}
		}
	}
}
int main() {
	int i = 0;
	double ans = 0.0;
	scanf("%lf %lf", &m, &n);
	while(m + n != 0){
		i = 0; ans = 0.0;
		while (i < m) {
			scanf("%lf %lf", &t[i], &v[i]);
			i++;
		}
		bubble(m);
		i = 0;
		while (n > 0 && i < m) {
			if (n >= t[i]) {
				n = n - t[i];
				ans = ans + v[i];
				i++;
			}
			else {
				ans = ans + v[i] * (n / t[i]);
				i++;
				break;
			}
		}
		printf("%.2lf\n", ans);
		scanf("%lf %lf", &m, &n);
}
	return 0;
}
char a[100];
	int i;
	gets(a);
	for (i = strlen(a) - 1; i >= 0; i--) {
		printf("%c", a[i]);
	}

/////////////////////////////////////
int isprime(int a) {
	int i, m;
	int flag;
	i = a;
	//scanf_s("%d", &n);
	flag = 1;
	for (m = 2; m < i/2; m++) {
		if (i % m == 0) {
			flag = 0;
		}
	}
	return flag;

}
int test(int i) {
	int b;
	b = 0;
	while (i > 0) {
		b = b * 10 + i % 10;
		i = i / 10;
	}
	return b;
}
int main(){
	int m, n,i,cnt;
	cnt = 0;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++) {
		if (test(i) == i && isprime(i)==1) {
			if (cnt <= 4) { printf("%6d", i); cnt++; }
			if (cnt == 5) { printf("\n"); cnt=0; }
		}
	}
	return 0;
}
/////////////////////////////////////////
int i = 8;
	printf("%d\t%d\t%d\t%d\n", ++i, --i, i++, i--);
	printf("%d", i);

int a[9][9], n, i, m,f,tmp;
	i = 8;
	f = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (m = 1; m <= n; m++) {
			scanf("%d", &a[i][m]);
			tmp = (n - i + 1) + m;
			if ( tmp <= n && a[i][m] != 0) { f = 0; }
		}
	}
	if (f == 1) { printf("YES"); }
	else { printf("NO"); }
int a, b, m, i, n;
	scanf("%d,%d", &a, &b);
	for (m = a; m <= b; m++) {
		for (i = m; i <= b; i++) {
			for (n = i; n <= b; n++) {
				if (m * m + i * i == n * n) { printf("%d^2+%d^2=%d^2\n", m, i, n); }
			}
		}
	}
* 	int a[100][100];
	//printf("wtf");
	int i, m,n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (m = 1; m <= n; m++) {
			scanf("%d", &a[i][m]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (m = 1; m < n; m++) {
			printf("%d ", a[m][i]);
		}
		printf("%d", a[m][i]);
		printf("\n");
	}


int a[2000];
int b[2000];

void bubble(int n) {
	int i,m; int c;
	for (i = n-2; i >= 0; i--) {
		for (m = 0; m <= i; m++) {
			if (a[m] > a[m + 1]) {
				c = a[m];
				a[m] = a[m + 1];
				a[m + 1] = c;
			}
		}
	}
	for (i = n - 2; i >= 0; i--) {
		for (m = 0; m <= i; m++) {
			if (b[m] > b[m + 1]) {
				c = b[m];
				b[m] = b[m + 1];
				b[m + 1] = c;
			}
		}
	}
}

int main() {
	int n, i, v, d,e;
	scanf("%d", &n);
	while (n != 0) {
		v = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		bubble(n);
		for (i = 0; i < n; i++) {
			for (e = n - 1; e >= 0; e--) {
				if (a[i] > b[e]) { v++; b[e] = 32767; break; }
			}
		}
		if (v > n / 2) { printf("YES\n"); }
		else { printf("NO\n"); }
		scanf("%d", &n);
	}

	return 0;
}

/////w5////
long a, b, n, m, i, k, ans, f,tmp;
	scanf("%ld %ld", &n,&m);
	for (a = n; a <= m; a++) {
		f = 1; ans = 0;
		for (k = 1; k <= a / 2; k++) {
			if (a % k == 0) { ans = ans + k; }
		}
		if (ans <= a) { continue; }
		tmp = ans;
		ans = 0;
		for (k = 1; k <= tmp / 2; k++) {
			if (tmp % k == 0) { ans = ans + k; }
		}
		if(a==ans){ printf("%ld %ld\n", a, tmp); }
	}

char a[90];
	int i, m,ans;
	ans = 0;
	m = 1;
	gets(a);
	for (i = strlen(a); i >= 0; i--) {
		if (a[i] > '0' && a[i] < '9') {
			ans = ans + (a[i] - '0') * m;
			m = m * 16;
		}
		if (a[i] > 'a' && a[i] < 'f') {
			ans = ans + (a[i] - 'a'+10) * m;
			m = m * 16;
		}
	}
	printf("%d", ans);
int x, y, cnt;  //x为2×2的空位子数量，y为1×1的空位子数量
	int a1, a2, a3, a4, a5, a6; //6个包裹的大小
	int c[4] = { 0,5,3,1 };  //当有3×3的时，则2×2的空位子数量可能的个数，这是3×3到2×2的空位子数量的映射
		cnt = 0;
		scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);

		cnt += a6 + a5 + a4 + (a3 + 3) / 4;  //a6和a5和a4以及（a3+3）/4都分别占用一个箱子，（a3+3）/4是对a3每满4向上取整的个数
		x = 5 * a4 + c[a3 % 4];   //这是计算2×2空位子的总个数，每一个a4装的箱子都有着5个2×2的空位子+每一个a3装的箱子可能存在2×2的空位子数量
		if (a2 > x)   //计算a2的数量是否大于其空位子的数量
			cnt += (a2 - x + 8) / 9;  //计算a2填满空位子后剩余的a2所需要的箱子的个数。（a2-x+8）/9是对a2每满9向上取整的箱子个数
		y = 36 * cnt - 36 * a6 - 25 * a5 - 16 * a4 - 9 * a3 - 4 * a2;  //计算剩余1×1空位子的个数
		if (a1 > y)//计算a1的数量是否大于其空位子的数量
			cnt += (a1 - y + 35) / 36;//计算a1填满空位子后剩余的a1所需要的箱子的个数.(a1-y+35)/36是对a1每满36向上取整的箱子个数
		printf("%d\n", cnt);

char s[2001][21];
	int m, n, a[10000], b[10000], k = 0, i;
	scanf("%d ", &m);
	for (n = 0; n < m; n++)
	{
		gets(s[n]);
		a[n] = strlen(s[n]);
		if (a[n] < 6)b[n] = 1;
		if (fuk(s[n]) == 1 && a[n] > 5)b[n] = 1;
		if (fuk(s[n]) == 2 && a[n] > 5)b[n] = 2;
		if (fuk(s[n]) >= 3 && a[n] > 5)b[n] = 3;
	}
	for (i = 0; i <m; i++)
	{
		if (b[i] == 1)printf("Not Safe\n");
		if (b[i] == 2)printf("Medium Safe\n");
		if (b[i] == 3)printf("Safe\n");
	}

* //////////////////////////////
int fuk(char s[21]) {
	int m, n, a = 0, b = 0, c = 0, d = 0, k = 0;
	n = strlen(s);
	for (m = 0; m < n; m++)
	{
		if (s[m] >= '0' && s[m] <= '9') { a = 1; }
		else if (s[m] >= 'a' && s[m] <= 'z') { b = 1; }
		else if (s[m] >= 'A' && s[m] <= 'Z') { c = 1; }
		else { d = 1; }
	}
	if (a == 1 && b == 1 && c == 1 && d == 1) { k = 4; }
	else if (a == 1 && b == 1 && c == 1 || a == 1 && b == 1 && d == 1 || a == 1 && c == 1 && d == 1 || d == 1 && b == 1 && c == 1) { k = 3; }
	else if (a == 1 && b == 1 || a == 1 && c == 1 || a == 1 && d == 1 || c == 1 && b == 1 || d == 1 && b == 1 || d == 1 && c == 1) { k = 2; }
	else if (a == 1 || b == 1 || c == 1 || d == 1) { k = 1; }

	return k;
}
/////////////////
int a[30000],i,k,m,n,t1,t2,ans;
	scanf("%d %d", &m, &n);
	for (i =0; i <= m; i++) {
		a[i] = 1;
	}
	for (k = 1; k <= n; k++) {
		scanf("%d %d", &t1, &t2);
		for (i = t1; i <= t2; i++) {
			a[i] = 0;
		}
	}
	ans = 0;
	for (i = 0; i <= m; i++) {
		ans = ans + a[i];
	}
	printf("%d", ans);
float tmp, max, min,i,sum;
	min = 10;
	max = 0;
	sum = 0;
	for (i = 0; i < 10; i++) {
		scanf("%f", &tmp);
		sum = tmp + sum;
		if (tmp > max) { max = tmp; }
		if (tmp < min) { min = tmp; }
	}
	sum = sum - max - min;
	sum = sum / 8.0;
	printf("%.3f", sum);

char a[2000], c;
	int i;
	gets(a);
	//scanf("%s ", a);
	scanf("%c", &c);
	for (i = 0; i < strlen(a); i++) {
		if (a[i] != c) { printf("%c", a[i]); }
	}
long m,n,a1, b1,a2, b2, a3, b3,t1, t2, t3;

	scanf("%ld %ld", &m, &n);
	b1 = m % 100;
	a1 = m / 100;
	b2 = n % 100;
	a2 = n / 100;
	t1 = a1 * 60 + b1;
	t2 = a2 * 60 + b2;
	t3 = abs(t2 - t1);
	a3 = t3 / (60);
	t3 = t3 - a3 * 60;
	b3 = t3;
	printf("%ld hrs ", a3);
	printf("%ld mins", b3);
float a;
	scanf("%f", &a);
	printf("%6.2f\n", a);
	printf("%6.2f %6.2f\n", a,a);
	printf("%6.2f %6.2f %6.2f\n", a,a,a);

void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int main(){
	long a, b, c, d, i;
	c = 1;
	d = 1;

	scanf("%ld %ld", &a, &b);
	if (a > b) { swap(&a, &b); }
	for (i = a * b; i >= b; i--) {
		if (i % a == 0 && i % b == 0) {
			d = i;
		}
	}
	for (i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			c = i;
		}
	}
	printf("%ld %ld", d, c);
}

int n, m,i,k,ans;
	int a[1000], b[1000];
	scanf("%d %d", &n, &m);
	ans = 32767;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		for (k = 0; k < n; k++) {
			if (ans > abs(b[i] - a[k])) { ans = abs(b[i] - a[k]); }
		}
	}
	printf("%d", ans);
long a, b,n,i,k,ans,f;
	scanf("%ld", &n);
	for (i = 0; i < n; i++) {
		scanf("%ld %ld", &a, &b);
		f = 1; ans = 0;
		for (k = 1; k <= a / 2; k++) {
			if (a % k == 0) { ans = ans + k; }
		}
		if (ans != b) { f = 0; }
		ans = 0;
		for (k = 1; k <= b / 2; k++) {
			if (b % k == 0) { ans = ans + k; }
		}
		if (ans != a) { f = 0; }
		if (f) { printf("YES\n"); }
		else{ printf("NO\n"); }

	}

long a1, b1, c1, a2, b2, c2, a3,b3,c3,t1, t2,t3;

	scanf("%ld:%ld:%ld", &a1, &b1, &c1);
	scanf("%ld:%ld:%ld", &a2, &b2, &c2);
	t1 = a1 * 60 * 60 + b1 * 60 + c1;
	t2 = a2 * 60 * 60 + b2 * 60 + c2;
	t3 = abs(t2 - t1);
	a3 = t3 / (60 * 60);
	t3 = t3 - a3 * 60 * 60;
	b3 = t3 / 60;
	t3 = t3 - b3 * 60;
	c3 = t3;
	printf("%ld:", a3);
	if (b3 < 10) { printf("0%ld:", b3); }
	else { printf("%ld:", b3); }
	if (c3 < 10) { printf("0%ld\n", c3); }
	else { printf("%ld\n", c3); }

int a, b, m, n;
	char x[50][50], y[50][50];
	while (scanf("%d %d", &m, &n) != EOF) {

		for (a = 0; a < m; a++) {
			scanf("%s", &x[a]);
		}
		for (a = 0; a < n; a++) {
			scanf("%s", &y[a]);
		}
		for (a = 0; a < m; a++) {
			for (b = 0; b < n; b++) {
				if (strcmp(x[a], y[b]) == 0) {
					printf("Yes\n");
					break;
				}
			}
			if (b == n) {
				printf("No\n");
			}
		}
	}

int a[100][100];
	int i, j;
	int n;
	scanf("%d", &n);
	a[0][0] = 1;
	printf("%d\n", a[0][0]);
	for (i = 1; i < n; i++) {
		a[i][0] = 1;
		a[i][i] = 1;
		for (j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
		for (j = 0; j < i; j++) {
			printf("%d ", a[i][j]);
		}
		printf("%d\n", a[i][j]);
	}

int  i, ans;
	int a, n;
	int b[5];
	//i = 0;
	//char n,a[80];
	ans = 0;
	scanf("%d", &a);
	for (i = 1; i <= 4; i++) {
		b[i] = a % 10;
		ans = ans + b[i];
		//b[i] = (b[i] + 9) % 10;
		a = a/10;
	}

	printf("%d",ans);
	int n,i;
	float a[100],max,min;
	min = 32767;
	max =  -32767;

	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%f", &a[i]);
		if (  a[i] <min) { min = a[i]; }
		if ( a[i]> max) { max = a[i]; }
	}
	for (i = 0; i < n; i++) {
		a[i] = (a[i] - min) / (max - min);
		printf("%.3f ", a[i]);
	}


int add(int i){
	int a, b, c;
	b = 0;
	a = i;
	while (i > 0){
		b = b * 10 + i % 10;
		i = i / 10;
	}

	a = a + b;
	return a;
}
int test(int i){
	int a, b, c, d;
	b = 0;
	while (i > 0){
		b = b * 10 + i % 10;
		i = i / 10;
	}
	return b;
}
int main(){
	int m, n, k, d, a, b, i;
	scanf("%d %d", &m, &n);

	for (k = m; k <= n; k++){
		d = 0;
		a = k;
		for (i = 1; i <= 15; i++){
			if (test(a) != a){
				d++;
				a = add(a);
			}
			else {
				printf("%d(%d):%d\n", k, d, a);
				break;
			}

		}
		if(i==16) { printf("%d(?):\n", k); }
	}
	return 0;
}
????????????????????????????????????????
char a[100][20];
int i, m, n;
char oo = 'a';
int ise(char c) {
	int flag = 0;
	if (c <= 90 && c >= 65 || c <= 122 && c >= 97) { flag = 1;  }//printf("yes");
	return flag ;
}
void gete(int c) {
	m = 0;
	while (!ise(scanf("%c", &a[c][m]))) {
		continue;
	}
	m++;
	while (ise(scanf("%c", &a[c][m]))) {
		//printf("%c\n", a[c][m]);
		m++;
	}
	a[c][m] = '\0';
}

void geten() {
	i = 0,m=0;
	a[0][0] = 0;
	while (a[i][m]!=10&& a[i][m] != 13) {
		gete(i);
		i++;
	}
}


int main() {
	//if (ise(oo)) { printf("yes"); }
	geten();
	for (n = 0; n <= 7; n++) {
		printf("%s",a[n]);
	}




????????????????????????????????????
double m, n, i, ans;
	scanf("%lf", &n);
	m = 100.0;
	ans = m;
	for (i = 1; i <= n; i++) {
		m = m / 2;
		ans = ans + 2 * m;
	}
	ans = ans - 2*m;
	printf("共经过%.5lf米\n", ans);
	printf("第n次反弹%.5lf米", m);


char a;
	int i,e,n,s,o;
	e = 0; n = 0; s = 0; o = 0;
	for (i = 1; i <= 20; i++) {
		scanf("%c", &a);
		if (a >= 65 && a <= 90 || a >= 97 && a <= 122) { e++; }
		else if (a >=48 && a <= 57 ) { n++; }
		else if (a == 10 || a == 32) { s++; }
		else { o++; }

	}

	printf("%d个英文字母\n", e);
	printf("%d个数字字符\n", n);
	printf("%d个空格或回车\n",s);
	printf("%d个其他字符\n",o);

float a, n,s;
	scanf("%f",&a);
	s = 0.0;
	n = 1.0;
	while (s<=a) {
		s = s + 1.0 / n;
		n++;
		printf("s=%.4f,n=%.0f\n", s, n);
	}
	n--;
	printf("s=%.4f,n=%.0f\n", s,n);
int a;
	while (scanf("%d", &a) != EOF) {
		if (a <= 100&&a>=0) {
			a = a / 10;
			switch (a) {
			case(10):
			case(9):printf("A\n"); break;
			case(8):printf("B\n"); break;
			case(7):printf("C\n"); break;
			case(6):printf("D\n"); break;
			default:printf("E\n"); break;
			}
		}
		else { printf("Score is error!\n"); }
	}

int a, b, c;
	scanf("%d",&a);
	for (b = 1; b <= 2 * a - 1; b++) {
		for (c = 1; c <= abs(a - b);c++) {
			printf(" ");
		}
		for (c = 1; c <= a-abs(a-b); c++) {
			printf("%d",c);
		}
		for (c = a - abs(a - b) -1; c >=1; c--) {
			printf("%d", c);
		}
		printf("\n");

	}
int a, b, c, ans,i;
	int d[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int e[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d %d %d",&a,&b,&c);
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
		ans = 0;
		for (i = 0; i < b - 1; i++) {
			ans = ans + d[i];
		}
		ans = ans + c;
		printf("%d", ans);

	}
	else {
		ans = 0;
		for (i = 0; i < b - 1; i++) {
			ans = ans + e[i];
		}
		ans = ans + c;
		printf("%d", ans);

	}
char a[50][50];
	int i;
	for (i = 1; i <=3; i++) {
		scanf("%s",&a[i]);
		//gets(a[i]);
	}
	for (i = 1; i <= 3; i++) {
		printf("%s\n", a[i]);
	}
int m, n, i, j;
	char s[50], p[50];
	while (scanf_s("%d %d", &m, &n) != EOF)
	{
		for (i = 0; i < m; i++)
		{
			scanf_s("%s", s[i]);
		}
		for (j = 0; j < n; j++)
		{
			scanf_s("%s", p[j]);
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (strcmp(s[i], p[j]) == 0)
				{
					printf("YES\n");
					break;
				}

			}
			if (i == n) { printf("NO\n"); }
		}
	}


	float a, b, c, s, max,ar, cc;
	int flag = 0;
	scanf("%f %f %f", &a,&b,&c);
	if (a > b) { max = 1; }
	else { max = 2; }
	if (c > a && c > b) { max = 3; }

	if (max == 1) { if (a >= b + c) { printf("There sides do not correspond to a valid triangle"); flag = 1; } }
	if (max == 2) { if (b >= a + c) { printf("There sides do not correspond to a valid triangle"); flag = 1; } }
	if (max == 3) { if (c >= b + a) { printf("There sides do not correspond to a valid triangle"); flag = 1; } }
	if (flag==0)
		{
			s = (a + b + c) / 2;
			ar = sqrt(s * (s - a) * (s - b) * (s - c));
			cc = a + b + c;

			printf("%.2f %.2f", ar,cc);
		}


char a[100];
	int i;
	gets(a);

	//scanf_s("%s",&a);
	for (i = 0; i <= strlen(a) - 1; i++) {
		if (a[i] < 'z' && a[i] >= 'a') {
			a[i] = a[i] + 1;
		}
		else  if (a[i] == 'z') {
			a[i] = 'a';
		}
		printf("%c", a[i]);
	}

int a,h,m,s;
	scanf("%d",&a);
	h = a/3600;
	m = (a - h * 3600) / 60;
	s = (a - h * 3600 - m * 60);
	printf("%dS=%dH%dM%dS",a,h,m,s);
int n, m, i;
	int a[100];
	scanf("%d", &n);
	for (m = 1; m <= n; m++) {
		scanf("%d", &a[m]);
	}
	for (m = n; m >=2; m--) {
		printf("%d ", a[m]);
	}
	printf("%d", a[m]);
int a[100][100];
	int n,m,i;
	//scanf("%d",&n);
	n = 3;
	for (i = 1; i <= n; i++) {
		for (m = 1; m<= n; m++) {
			scanf("%d", &a[i][m]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (m = 1; m<= n; m++) {
			printf("%d ", a[m][i]);
		}
		printf("\n");
	}





int a[100],b[100], i, m, n;
	scanf("%d %d", &i, &m);
	m = i + m;

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a[i],&b[i]);
	}

	for (i = m-2; i >= 0; i--) {
		for (n = 0; n <= i; n++) {
			if (a[n] > a[n + 1]) {
				swap(&a[n], &a[n + 1]);
				swap(&b[n], &b[n + 1]);
			}
		}
	}
	for (n = 0; n <m; n++) {
		printf("%d %d\n",a[n],b[n]);
	}
return 0;
*
int i,n;
char xh[100][100], xm[100][100];
int a[100], b[100], c[100],max=0,maxp=1;
float ava=0.0, avb=0.0, avc=0.0;

void input(int d) {
	scanf("%s %s %d %d %d",&xh[d],&xm[d],&a[d],&b[d],&c[d]);
	if (a[d] + b[d] + c[d] > max) {
		max = a[d] + b[d] + c[d];
		maxp = d;
	}
	ava = ava + a[d];
	avb = avb + b[d];
	avc = avc + c[d];

}
void output(int d) {
	printf("%s %s %d %d %d\n", xh[d], xm[d], a[d], b[d], c[d]);

}


int main() {
	scanf("%d", &n);
	for (i = 1; i <= n;i++) {
		input(i);
	}
	ava = ava / n;
	avb = avb / n;
	avc = avc / n;

	printf("%.0f %.0f %.0f\n", ava, avb, avc);
	output(maxp);

//////////////////////////buble//////////////////
int i, m,a[10];
	for (i = 0; i <= 2; i++) {
	scanf("%d", &a[i]);
	}

	for (i = 1; i >=0; i--) {
		for (m =0; m <= i; m++) {
			if (a[m] > a[m + 1]) { swap(&a[m] , &a[m + 1]); }
		}
	}

	printf("%d %d %d ", a[0],a[1],a[2]);


	a = n / 1000;
	b = (n % 1000 - n % 100) / 100;
	c = (n % 100 - n % 10) / 10;
	d = n % 10;
char a[200];
	int i;
	//gets(a);

	scanf("%s", &a);

	for (i = 0; i <= strlen(a) - 1; i++) {
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
		printf("%c", a[i]);

		}



	}
double m, n, i, ans;
	m = 100.0;
	scanf_s("%lf", &n);
	ans = m;
	for (i = 1; i <= n; i++) {
		m = m / 2;
		ans = ans + 2 * m;
	}
	ans = ans - m;


	printf("dalength=%.4lf\n", ans);
	printf("high=%.4lf ", m);
float min, max, a[100];
	int i,n;
	scanf_s("%d",&n);
	for (i = 1; i <= n; i++) {
		scanf_s("%f", &a[i]);
	}
	min = a[1];
	max = a[1];
	for (i = 1; i <= n; i++) {
		if (a[i] < min) { min = a[i]; }
		if (a[i] > max) { max = a[i]; }
	}
	printf("%.0f %.0f", max, min);
float min,max,a[5];
	int i;
	for (i = 1; i <= 4;i++) {
		scanf_s("%f", &a[i]);
	}
	min = a[1];
	max = a[2];
	for (i = 1; i <= 4; i++) {
		if (a[i] < min) { min = a[i]; }
		if (a[i] > max) { max = a[i]; }
	}
	printf("%.2f %.2f",max,min);

	char a[100];
	int i, n, t;
	scanf_s("%d\n",&n);
	//scanf_s("%s", &a);
	gets(a);
	t = 0;
	i = strlen(a)-1;
	while (t == n) {
		i = i - 1;
		if (i < 0) { i = strlen(a) - 1; }

		t++;
	}
	t = 0;
	i--;
	if (i < 0) { i = strlen(a) - 1; }

	while (t != strlen(a)) {

		if (i == strlen(a)) { i = 0; }
		printf("%c",a[i]);
		i = i + 1;
		t++;
	}




int p, n;
	float a, ans;
	p = 0;
	n = 0;
	ans = 0.0;
	a = 1;

	while (1) {
		scanf_s("%f",&a);
		if (a > 0) { p++; }
		if (a < 0) { n++; }
		ans = ans + a;
		if (a ==0) { break; }
	}
	printf("%d %d %.3f",p,n,ans);


if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		printf("yes");
	}
	else { printf("no"); }


	int n,m=4,i;
	char a[100];
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++) {
		a[i] = getchar();// scanf_s("%c", &a[i]);
	}

printf("\n");
scanf_s("%d", &m);
for (i = m; i <= n; i++) {
	printf("%c", a[i]);
}

int i;
	char a[100];
	gets(a);

	//scanf_s("%s",&a);
	for (i = strlen(a)-1; i >=0 ; i--) {
		printf("%c", a[i]);
	}

	//printf("\n");
void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;

}
int cnm(float a, int b,int c) {
	float s;
	s = (a + b + c) / 2;
	return (c);
}
int main() {
	int a, b,c;
	scanf_s("%d %d",&a,&b);
	c=cnm(a,b);
	printf("%d",c);
	return 0;
}*/






/*char a[100];
	gets(a);
	int i;

	//scanf_s("%s",&a);
	for (i = 0; i < strlen(a); i++) {
		printf("%c ", a[i]);
	}
	printf("%c ", a[i]);

	char a[100],b[100];
	gets(a);
	gets(b);

	//scanf_s("%s",&a);
	for (int i = 0; i <= strlen(a); i++) {
		printf("%c", a[i]);
	}
	for (int i = 0; i <= strlen(b); i++) {
		printf("%c", b[i]);
	}
	//printf("\n");

int x, y,ans1,ans2;
	scanf_s("%d %d",&x,&y);
	ans1 = minx(x,y);
	ans2 = maxx(x,y);
	printf("%d %d",ans1,ans2);


	///////////////////////////////////////////
int minx(int a,int b) {
	int c=0,i;
	for (i = 2; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			c = i;
		}

	}

	return(c);
}
int maxx(int a, int b) {
	int c=0, i;
	for (i = a*b; i >= a; i--) {
		if (i % a == 0 && i % b == 0) {
			c = i;
		}

	}

	return(c);
}

void swap(int *a,int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;

}
///////////////////////////////////////////

int main() {
	int a[11],i,n,m;
//	int a, b;
//	scanf_s("%d %d", &a,&b);
	for(i=1;i<=10;i++){
		scanf_s("%d",&a[i]);

	}
	n = 10;
	for (i = 9; i >= 1; i--) {

		if (a[n] < a[i]) {
			swap(&a[n], &a[i]);
			n = i;
		}


	}
	for (i = 1; i <= 10; i++) {
		printf("%d\n", a[i]);
	}
//scanf_s("%d", &a[i]);
//	swap(&a, &b);
//	printf("%d %d",a,b);
double err = 0.0001;
	double c, t,a;
	double b, d;

	scanf_s("%lf", &c);
	t = c;
	a = t - c / t;

	while (a > err * t) {


		t = (c / t + t) / 2.0;
		a = t - c / t;
		b = a / a;
		a = a * b;
	}
	printf("%.2lf", &t);

float m,ans=0;
	int i, n;
	scanf_s("%f %d",&m,&n);
	ans = m;
	for (i = 1; i < n; i++) {
		m = m / 2;
		ans = ans + m*2;
	}
	m = m / 2;
	printf("%.2f %.2f",m,ans);



#include <stdio.h>

int main() {
	float a, b,ans,tmp, i, n;
	scanf_s("%f",&n);
	a = 2;
	b = 1;
	ans = 0;

	for (i = 1; i <= n; i++) {
		ans = ans + a / b;
		tmp = a;
		a = a + b;
		b = tmp;

	}
	printf("%.2f",ans);





	return 0;
}
int o = 10;
	int a[6];
	int i,n,m;
	scanf_s("%d", &n);
	i = 1;
	while (n >= 1) {
		a[i] = n % 10;
		n = n / o;
		i++;
	}
	i--;
	printf("%d\n", i);



	printf("%d", a[i]);
	for (m = i-1; m >= 1; m--) {
		printf(" %d", a[m]);

	}
	printf("\n");
	for (m = 1; m <= i; m++) {
		printf("%d", a[m]);

	}

	return 0;
* int a, b, c,aa,ab,ac;
	a = 100;
	b = 0;
	c = 0;
	aa = 0;
	ab = 0;


	ac = 1000;
		for (b = 1; b <= 10; b++) {
			for (a = 1; a <= 10; a++) {
				if (369-a*69 - b * 39  <= ac && 369 - a * 69 - b * 39>=0) {
					aa = a;
					ab = b;
					ac = 369 - a * 69 - b * 39;
				}


			}
		}
	printf("%d %d %d", aa,ab,ac);

* int flag,i,m,l,cnt;
	//n = 200;
	cnt = 0;
	scanf_s("%d %d", &i,&l);
	if (i == 1) { i = 2; }
	flag = 1;
	for(i;i<=l;i++){
		flag = 1;
	for (m = 2; m < i; m++) {
		if (i % m == 0 || i==1) {
			flag = 0;
		}

	}
	if (flag == 1) {
		cnt++;
	}
	}
	printf("%d\n",cnt);

int c[10], i, m,n,t,f;
	n = 1;
	f = 1;
	t = 9;
	for (i = 0; i <= 9; i = i + 1) {
		c[i] = 1;

	}
	i = 0;
	while (i <= 1000) {
		for (m = 1; m <= n; m++) {
			t = t + 1;
			if (t == 10) { t = 0; }
		}
		c[t] = 0;

		i++;
			n++;
	}
	for (i = 1; i <= 10; i = i + 1) {


		if (c[i] == 1 && f == 0) {
			printf(" %d", i+1);
		}
		if (c[i] == 1 && f == 1) {
			printf("%d", i+1);
			f = 0;
		}

	}

/*


*/