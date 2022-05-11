import React from 'react';
import styled from 'styled-components';
import NewsItem from './NewsItem';
import axios from 'axios';
import usePromise from '../lib/usePromise';

const NewsListBlock = styled.div`
  box-sizing: border-box;
  padding-bottom: 3rem;
  width: 768px;
  margin: 0 auto;
  margin-top: 2rem;
  @media screen and (max-width: 768px) {
    width: 100%;
    padding-left: 1rem;
    padding-right: 1rem;
  }
`;

const NewsList = ({ category, country, topic, onArticles}) => {
  const [loading, response, error] = usePromise(() => {
    console.log(      category, country, topic
    );
    const query = category === 'all' ? '' : `&category=${category}`;

    return axios.get(
      `https://newsapi.org/v2/top-headlines?country=${country}${query}&apiKey=21f09a46c77e4f5a92bdc4fcc2025774`,
    ).then((res)=>{
      return Promise.resolve(res.data.articles.filter(x=>x.title.toLowerCase().includes(topic.toLowerCase())))
    })
  }, [category, country, topic]);

  // 대기중일 때
  if (loading) {
    return <NewsListBlock>대기중...</NewsListBlock>;
  }
  // 아직 response 값이 설정되지 않았을 때
  if (!response) {
    return null;
  }

  // 에러가 발생했을 때
  if (error) {
    return <NewsListBlock>에러 발생!</NewsListBlock>;
  }

  // response 값이 유효할 때
  const articles = response;
  onArticles(articles);
  return (
    <NewsListBlock>
      {articles.map(article => (
        <NewsItem key={article.url} article={article} category={category} country={country} topic={topic}/>
      ))}
    </NewsListBlock>
  );
};

export default NewsList;
