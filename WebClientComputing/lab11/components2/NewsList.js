import React, { useEffect } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import styled from 'styled-components';
import NewsItem from './NewsItem';
import axios from 'axios';
import usePromise from '../lib/usePromise';
import { articlesSearch } from '../module/search';

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

const NewsList = () => {
  const category = useSelector(state => state.category);
  const country = useSelector(state => state.country);
  const topic = useSelector(state => state.topic);

  const [loading, response, error] = usePromise(() => {
    console.log(category, country, topic);
    const categoryQuery = category === 'all' ? '' : `category=${category}&`;
    const countryQuery = `country=${country}&`;
    const topicQuery = topic === '' ? '' : `q=${topic}&`;
    return axios.get(
//      `https://newsapi.org/v2/top-headlines?country=kr&q=KBS${query}&apiKey=0a8c4202385d4ec1bb93b7e277b3c51f`,
//        `https://newsapi.org/v2/top-headlines?country=kr${category}&apiKey=0a8c4202385d4ec1bb93b7e277b3c51f`,
        `https://newsapi.org/v2/top-headlines?${countryQuery}${topicQuery}${categoryQuery}apiKey=21f09a46c77e4f5a92bdc4fcc2025774`,
//        `/news/v2/top-headlines?country=kr${query}&apiKey=0a8c4202385d4ec1bb93b7e277b3c51f`,
);
  }, [category, country, topic]);

  // response 값이 유효할 때
  const { articles } = response ? response.data : {articles:null};
  const dispatch = useDispatch();
  useEffect(()=>{ 
    dispatch(articlesSearch(articles));
  }, [articles, dispatch]);
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


  
  return (
    <NewsListBlock>
      {articles.map(article => (
        <NewsItem key={article.url} article={article} />
      ))}
    </NewsListBlock>
  );
};

export default NewsList;
