 <img src="https://user-images.githubusercontent.com/76942710/197327798-dfaf79a9-2814-41b4-9129-86c0e6ecc15e.jpg" width = "20%" height="20%" align="right" > 

# #개발자를 꿈꾸는
끊임없이 궁금해하는

원활하게 소통하는

맡은 일에 최선을 다하는

개발자를 꿈꾸는 황상진 입니다.

<h1> Profile
<h6>  
  
**황상진(Hwang Sang Jin)**

✆ **010-8633-4421**

✉ **wls4421@gmail.com**

<h1> Education
<h5>  2013.3 ~ 2016.2  
<h6>
  서울대성고등학교
<h5>  2017.2 ~
<h6>
  가톨릭대학교 성심교정 컴퓨터정보공학부(2017.2 ~ )  
 
 
  -  이수학점 119/130  
  -  평점평균 3.72/4.5  
 
 
  
<h1> Stack
  <h5> Python
  <h5> C/C++
  <h5> Java
  <h5> MySQL
  <h5> Git
  <h5> AWS

## Projects
  - [MOOD](#mood)
  - [SPY GAME](#spy)  
  
## 숙소 추천 알고리즘 MOOD(Make yOur Own Destination)<a id="mood"></a>
   
## Table of contents
  - [Process](#process)
  - [My Part](#part)
  - [References](#reference)
  - [Used Technology](#tech)
  - [Architecture](#arch)
<h4> Process<a id="process"></a>
<h6>  

  * 2022.03 - 아이디어 구체화 및 기획  
  
  * 2022.04 - 데이터 형식 통일화 및 리뷰 데이터 크롤링  
  
  * 2022.05 - 단어 임베딩 및 클러스터링  
  
  * 2022.06 - 결과 확인 및 평가  
  
<h4> My Part<a id="part"></a>  
 
<h6>  
    -  Agoda 사이트 호텔 데이터 크롤링  
    
    -  NLP(Natural Language Processing: 자연어처리)  
    
    -  Embedding(임베딩)&Clustering(클러스터링)
  
  
  
<h4> References<a id="reference"></a>  
<h6>   

   * Hyungsuc Kang, Janghoon Yang, “Optimization of Word2vec Models for Korean Word Embeddings”   
    
   * Jee-Uk Heu, “Korean Language Clustering using Word2Vec”  
   
<h3> Used Technology <a id="tech" ></a>
<div align = "center">
   <img src="https://user-images.githubusercontent.com/76942710/197331078-2f9411f1-aa93-4675-9f3e-a60b5c5acd16.png" width = "80%" height="80%">  
</div>

<h3> Architecture <a id="arch" ></a>
<div align ="center">
   <img src="https://user-images.githubusercontent.com/76942710/197331096-3d2ae60f-c0f2-4901-b266-4d2da2ed0708.png" width = "100%" height="100%"> 
</div>
<h6>
<div align = "left" >
 
  1. 숙소 리뷰 사이트에서 리뷰 데이터를 크롤링합니다.  
  
  2. 리뷰 데이터를 자연어 처리하여 임베딩&클러스터링 합니다.  
  
   -> NLP(Natural Language Processing: 자연어처리), 리뷰 데이터의 명사 형용사 추출을 진행하기 위해 KoNLPy를 사용합니다.  
  
   -> 추출한 단어를 300차원 벡터로 임베딩합니다. 임베딩한 단어를 150개로 군집화(클러스터링)하여 이후 사용자의 성향 분석 문항에 이용합니다.  
  
  3. 리뷰를 작성한 user 각각의 장소별로(클러스터링 그룹별로) 수치를 데이터화 합니다.  
  <div align ="center">
   <img src="https://user-images.githubusercontent.com/76942710/197342042-d8b98312-1205-4ca0-8847-85d705a8e3a0.png" width = "70%" height = "70%">
   </div>  
   
  4. 수치화한 데이터를 기반으로 협업 필터링 모델을 제작합니다.  
  
  
  5. 사용자는 클러스터링 데이터를 기반으로 작성된 성향 분석 문항에 응답하고 이를 Input Data로 수치화합니다.
  <div align ="center">
   <img src="https://user-images.githubusercontent.com/76942710/197342212-3f111c1c-b74b-41df-8ed9-c8c45470a05a.png" width = "50%" height = "50%">
   </div>
  
  6. Input Data와 비슷한 성향의 user가 평가한 장소(숙소)가 설정한 임계값을 넘어갈 때 이를 추천합니다.
  <div align ="center">
   <img src="https://user-images.githubusercontent.com/76942710/197342349-06a31753-f598-4399-95bc-c2e7e9e52779.png" width = "50%" height = "50%">
   </div>
   
 프론트엔드 구현화 한 화면
   <div align ="center">
    <img src="https://user-images.githubusercontent.com/76942710/197327721-12ae246b-9f93-433a-8339-80f355ccd128.png" width = "25%" height="20%">  
   </div>
</div>
 
# SPY GAME <a id="mspy"></a>
   
## Table of contents
  - [Process](#process2)
  - [My Part](#part2)
  - [Used Technology](#tech2)
  - [Architecture](#arch2)
  - [Features](#feature)

<h4> Process<a id="process2"></a>
<h6>  

  * 2022.04 - 이미지 데이터 제작 및 기능 설계
  
  * 2022.05 - 기능 구현
  
  * 2022.06 - 버그 수정 및 사운드 파일 적용 
 
<h4> My Part<a id="part2"></a>
<h6>  
    -  팀 리더  
 
    -  컨셉, 오브젝트 기획
    
    -  기능구현
    
    -  사운드 파일 등 오픈소스 수급
  
<h3> Used Technology <a id="tech" ></a>
<div align = "center">
   <img src="https://user-images.githubusercontent.com/76942710/197350231-e687ee0f-5198-4179-83de-6a35f3afe32f.png" width = "40%" height="40%">  
</div>

<h3> Architecture <a id="arch2" ></a>
<div align ="center">
   <img src="https://user-images.githubusercontent.com/76942710/197352453-b3da05e8-454e-44e1-8f8d-07d21cdf956a.png" width = "70%" height="70%"> 
</div>

 <h6>
<div align = "left" >
<h3> Features <a id="feature" ></a>
  1. g_current_game_phase에 해당하는 클래스의 HandleEvent, Render, Update 객체가 main 함수에서 무한 루프의 형태로 반복됩니다.  
 
  2. PC에 전체 화면을 해상도 픽셀 단위로 랜더링합니다.
 
  3. 모든 GUI 오브젝트는 좌상단 {0,0}을 기준으로 픽셀 단위로 호출, 출력됩니다.
  
  ex) 64 * 120 pixel의 이미지에서 리소스의 픽셀로 호출하여 애니메이션을 구현합니다.
 
   <div>
   <img src="https://user-images.githubusercontent.com/76942710/197372636-51f1a598-5b54-4f21-af06-a612b737c93c.png" width = "10%" height = "10%">
   <img src="https://user-images.githubusercontent.com/76942710/197372717-5e93a39e-9ad1-4c1d-8cb1-81f981d51c2c.JPG" width = "10%" height = "10%">
   <img src="https://user-images.githubusercontent.com/76942710/197348889-9fd458b3-4e5c-44c9-ba95-d97b20ee8815.gif" width = "10%" height = "10%">
   </div>
   
 
</div>
