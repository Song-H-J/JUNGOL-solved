// 2024.07.25
// 송현준

#include <stdio.h>
#include <string.h>
/*
도화지의 가로, 세로 길이 100 px
색종이의 가로, 세로 길이  10 px

좌표계 세팅. 기존 좌표계를 x축 기준으로 회전해 사용

    0 -- x
    |
    y

*/


int main() {
    int num; // 색종이 개수
    int ver, hor; // 열, 행
    int cnt = 0;
    int paper[100][100]; // 도화지
    memset(paper, 0, sizeof(paper)); // 1이면 blak, 0이면 white
    scanf("%d", &num);

    for(int k = 0; k<num; k++)
    { // 색종이 갯수만큼 loop
        scanf("%d %d", &ver, &hor);
        // 첫번째는 왼쪽 변과 떨어진 정도이므로 열에 해당
        // 두번째는 아래쪽, 여기서는 위쪽 변과 떨어진 정도이므로 행에 해당
        int endh = hor + 10;
        int endv = ver + 10;
        // 색종이의 넓이만큼 paper를 채운다.
        // paper가 이미 채워져있다면 cnt를 플러스하지 않는다.
        // hor-1, ver-1부터 시작하지 않는 이유는
        // hor, ver 값은 떨어진 거리 값이므로
        // 채워지는건 그 다음 칸부터 채워져야 함이다.
        for(int i = hor; i<endh; i++)
        {
            for(int j = ver; j<endv; j++)
            {
                if(paper[i][j]==0)
                {
                    paper[i][j]++;
                    cnt++;
                }
            }
        }
    }

    printf("%d", cnt);
    return 0;
}
