import React, { useState } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import PropTypes from 'prop-types';
import Text from '../ui/Text';
import TextArea from '../ui/TextArea';

const Summary = () => {
  const articles = useSelector(state => state.articles);
  if(!Array.isArray(articles)) return null;
  const summary = articles.reduce((result,article,index) => `${result} (${index+1}) ${article.title}\n`, "");

  return (
    <>
      <Text large bold> {`뉴스 개수: ${articles.length}`} </Text> 
      <TextArea name={'뉴스 요약'} value={summary}/>
    </>
  );
}

Summary.propTypes = { onSelect: PropTypes.func };

export default Summary;
