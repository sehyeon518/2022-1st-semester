import React, { useState } from 'react';

const Say = () => {
  const [message, setMessage] = useState('');
  const [text, setText] = useState('');
  const [color, setColor] = useState('black');
  const onClickEnter = () => setMessage(`안녕!`);
  const onClickLeave = () => setMessage(`잘가!`);

  return (
    <div>
      <button onClick={onClickEnter}>입장</button>
      <button onClick={onClickLeave}>퇴장</button>
      <input onChange={(e) => setText(e.target.value)} />
      <h1 style={{ color }}>{`${text && `${text}, `} ${message}`}</h1>
      <button style={{ color: 'red' }} onClick={() => setColor('red')}>
        빨간색
      </button>
      <button style={{ color: 'green' }} onClick={() => setColor('green')}>
        초록색
      </button>
      <button style={{ color: 'blue' }} onClick={() => setColor('blue')}>
        파란색
      </button>
    </div>
  );
};

export default Say;
