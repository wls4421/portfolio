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
<h6>
  서울대성고등학교 (2013.3 ~ 2016.2)  

  

 
  가톨릭대학교 성심교정 컴퓨터정보공학부(2017.2 ~ 2024.2)  

  
  -  이수학점 132/130

 
  -  평점평균 3.66/4.5

 </h6>

<h1>Employment History
<h5>
 (주)위우너스 (2023.01 ~ 재직중)
</h5>
<h6>
프로젝트
<br>
    
- 메시지 포멧 GPS-100 -> ASTERIX 변환 SW 개발 (2024. 07 ~ 진행중)
  
  
- AI기반 전술 개발, 훈련용 모의비행 훈련체계 C2(Command And Control) 체계 개발 (2024.01 ~ 진행중)  
  
- KF-21 SIM/CPT 전술데이터링크 모의 SW 개발 (2023.04 ~ 2023.12)  
  
- K-UAM GC12 교통관제 서비스 SW 개발 (2023.03 ~ 2023.05)  
 
</h6>
  
<h1> Stack
  <h5> Python
   
  <h5> C/C++
   
  <h5> Git

## Projects
  - [MOOD](#mood)
  
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
    -  Agoda 사이트 호텔 데이터 크롤링 (Python - Selenium)
    
    -  NLP(Natural Language Processing: 자연어처리) (Python KoNLPy)
  
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
 
  
   
 

