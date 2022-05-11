import React from 'react';
import Text from '../ui/Text';
import TextArea from '../ui/TextArea';

const Summary=({articles}) => {
    let text="";

    for(let i = 0; i < articles.length; i++) {
        text += `(${i+1}) ${articles[i].title}\n`;
    }
    return(
        <>
        <Text large bold>뉴스 개수: {articles.length}</Text>
        <TextArea name={'뉴스 개수'} value={text}/>
        </>
    );
}

export default Summary;